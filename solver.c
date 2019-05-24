/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:30:15 by kmira             #+#    #+#             */
/*   Updated: 2019/05/23 14:35:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino *g_place_pruning[27] =
{
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

int g_counter = 0;

int		count_pieces(t_tetrimino *tetrimino)
{
	int	result;

	result = 0;
	while (result <= 26 && tetrimino[result].id != 0)
		result++;
	return (result);
}

#define PIECE_MASK (*(u_int64_t *)(tetrimino[current_piece].mask) >> col)

int		solve_board
	(t_tetrimino *tetrimino, unsigned short *board, int board_size)
{
	int	row;
	int	col;
	int	current_piece;

	row = 0;
	col = -1;
	current_piece = 0;
	while (current_piece >= 0)
	{
		while (row + tetrimino[current_piece].height <= board_size)
		{
			while (++col + tetrimino[current_piece].width <= board_size)
				if (((PIECE_MASK) & *(u_int64_t *)&board[row]) == 0 && g_counter++ > -1)
				{
					place_piece(&tetrimino[current_piece], board, &row, &col);
					print_solution_of(tetrimino, board_size, current_piece);
					if (board_is_solved(&current_piece, tetrimino, &row, &col))
						return (1);
				}
			col = -1;
			row++;
		}
		if (--current_piece >= 0)
			remove_piece(tetrimino[current_piece], board, &row, &col);
	}
	return (-1);
}

int		fill_board_with(t_tetrimino *tetrimino)
{
	unsigned short	board[16];
	int				board_size;
	int				pieces;

	board_size = 0;
	ft_bzero(board, sizeof(board));
	pieces = count_pieces(tetrimino);
	while (board_size * board_size < pieces * 4)
		board_size++;
	while (solve_board(tetrimino, board, board_size) == -1)
	{
		ft_bzero(board, sizeof(board));
		board_size++;
	}
	return (board_size);
}
