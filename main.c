/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:33:15 by kmira             #+#    #+#             */
/*   Updated: 2019/05/23 15:40:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_slow = 0;
int g_optimization = 0;

int	main(int aa, char **args)
{
	int			fd;
	const char	*file;
	t_tetrimino	tetriminos[MAX_TETRIMINO_PIECES];
	int			board_size;

	if (aa >= 3)
	{
		if (ft_strcmp(args[1], "-slow") == 0)
		{
			aa = 2;
			g_slow = 1;
			args[1] = args[2];
		}
		else if (ft_strcmp(args[1], "-fast") == 0)
		{
			aa = 2;
			g_slow = 0;
			args[1] = args[2];
		}
	}
	if (aa >= 2)
	{
		if (ft_strcmp(args[2], "-yes") == 0)
		{
			aa = 2;
			g_optimization = 3;
			args[1] = args[3];
		}
		else if (ft_strcmp(args[2], "-no") == 0)
		{
			aa = 2;
			g_optimization = 0;
			args[1] = args[3];
		}
	}
	if (aa != 2)
		EXIT("fillit: usage");
	file = args[1];
	fd = open(file, O_RDONLY);
	if (fd == INVALID_FILE)
		EXIT("usage: File does not exist");
	if (begin_reading(fd, tetriminos) == -1)
	{
		if (errno == INVALID_FILE_FORMAT)
			EXIT("error");
		else if (errno == INVALID_PIECE_FORMAT)
			EXIT("error");
		else
			EXIT("error");
	}
	write(1, "\n", 1);
	board_size = fill_board_with(tetriminos);
	printf("\e[?25h");
	fflush(stdout);
	final_print(tetriminos, board_size, count_pieces(tetriminos));
	return (0);
}
