/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:55:45 by kmira             #+#    #+#             */
/*   Updated: 2019/05/23 15:20:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <locale.h>
#include <wchar.h>

#define CHAR_LEN 10

extern int g_slow;
extern int g_counter;

void	write_piece(t_tetrimino piece, char *board_str, int board_size)
{
	int	bit;
	int	i;

	setlocale(LC_ALL, "");
	char *block = "█";
	bit = 1 << 15;
	i = 0;
	while (i < 4)
	{
		if (piece.mask[0] & bit)
		{
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 0 + 2] = '\033';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 1 + 2] = '[';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 2 + 2] = '3';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 3 + 2] = piece.color1;
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 4 + 2] = 'm';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 5 + 2] = '\0';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 6 + 2] = '\0';
			memcpy(&board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 0)) + 5 + 2], block, 3);
		}
		if (piece.mask[1] & bit)
		{
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 0 + 2] = '\033';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 1 + 2] = '[';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 2 + 2] = '3';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 3 + 2] = piece.color1;
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 4 + 2] = 'm';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 5 + 2] = '\0';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 6 + 2] = '\0';
			memcpy(&board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 1)) + 5 + 2], block, 3);
		}
		if (piece.mask[2] & bit)
		{
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 0 + 2] = '\033';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 1 + 2] = '[';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 2 + 2] = '3';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 3 + 2] = piece.color1;
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 4 + 2] = 'm';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 5 + 2] = '\0';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 6 + 2] = '\0';
			memcpy(&board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 2)) + 5 + 2], block, 3);
		}
		if (piece.mask[3] & bit)
		{
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 0 + 2] = '\033';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 1 + 2] = '[';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 2 + 2] = '3';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 3 + 2] = piece.color1;
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 4 + 2] = 'm';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 5 + 2] = '\0';
			board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 6 + 2] = '\0';
			memcpy(&board_str[(i * CHAR_LEN) + (piece.col_loc * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (piece.row_loc + 3)) + 5 + 2], block, 3);
		}
		bit = bit >> 1;
		i++;
	}
}

// int a = '▓';

void	print_solution_of(t_tetrimino *tetriminos, int board_size, int current_piece)
{
	char	board_str[MAX_BOARD_SIZE * MAX_BOARD_SIZE * CHAR_LEN];
	int		num_pieces;
	int		i;
	int		j;

	setlocale(LC_ALL, "");
	ft_memset(board_str, '\0', 16 * 16 * CHAR_LEN);
	i = -1;
	while (++i < board_size)
		board_str[(i * ((board_size * CHAR_LEN) + 1)) + (board_size * CHAR_LEN)] = '\n';
	i = -1;
	while (++i < board_size)
	{
		j = -1;
		while (++j < board_size)
		{
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 5] = '\033';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 6] = '[';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 7] = '0';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 8] = 'm';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 9] = '_';
		}
	}
	i = -1;
	num_pieces = current_piece;
	while (++i < num_pieces)
		write_piece(tetriminos[i], board_str, board_size);
	write(1, board_str, (board_size) * ((board_size * CHAR_LEN) + 1));
	printf("\e[?25h");
	printf("\e[?25l");
	printf("\e[%sA", ft_itoa(board_size + 1));
	// printf("\e[%s:%sH", ft_itoa(-board_size - 1), ft_itoa(-board_size));
	fflush(stdout);
	printf("Amount of verifications: %d\n", g_counter);
	printf("\e[?25h");
	// sleep(.5);
	if (g_slow == 1)
		nanosleep((const struct timespec[]){{0, 300000000L}}, NULL);
	else
		nanosleep((const struct timespec[]){{0, 7000000L}}, NULL);
}

void	final_print(t_tetrimino *tetriminos, int board_size, int current_piece)
{
	char	board_str[MAX_BOARD_SIZE * MAX_BOARD_SIZE * CHAR_LEN];
	int		num_pieces;
	int		i;
	int		j;

	ft_memset(board_str, '\0', 16 * 16 * CHAR_LEN);
	i = -1;
	while (++i < board_size)
		board_str[(i * ((board_size * CHAR_LEN) + 1)) + (board_size * CHAR_LEN)] = '\n';
	i = -1;
	while (++i < board_size)
	{
		j = -1;
		while (++j < board_size)
		{
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 5] = '\033';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 6] = '[';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 7] = '0';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 8] = 'm';
			board_str[(j * CHAR_LEN) + (((board_size * CHAR_LEN) + 1) * (i)) + 9] = '_';
		}
	}
	i = -1;
	num_pieces = current_piece;
	while (++i < num_pieces)
		write_piece(tetriminos[i], board_str, board_size);
	write(1, board_str, (board_size) * ((board_size * CHAR_LEN) + 1));
}
