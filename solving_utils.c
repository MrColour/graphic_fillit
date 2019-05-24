/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:49:17 by kmira             #+#    #+#             */
/*   Updated: 2019/05/23 20:12:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern t_tetrimino *g_place_pruning[27];
extern int g_optimization;

void	place_piece
	(t_tetrimino *tetrimino, unsigned short *board, int *row, int *col)
{
	tetrimino->row_loc = *row;
	tetrimino->col_loc = *col;
	*(u_int64_t *)&board[*row] =
		(*(u_int64_t *)&board[*row]) ^ (*(u_int64_t *)tetrimino->mask >> *col);
	if (g_optimization == 3)
	{
		tetrimino->last = g_place_pruning[tetrimino->type];
		g_place_pruning[tetrimino->type] = tetrimino;
	}
}

void	remove_piece
	(t_tetrimino tetrimino, unsigned short *board, int *row, int *col)
{
	*col = tetrimino.col_loc;
	*row = tetrimino.row_loc;
	*(u_int64_t *)&board[*row] =
		(*(u_int64_t *)&board[*row]) ^ (*(u_int64_t *)tetrimino.mask >> *col);
	if (g_optimization == 3)
		g_place_pruning[tetrimino.type] = tetrimino.last;
}

int		board_is_solved
	(int *current_piece, t_tetrimino *tetrimino, int *row, int *col)
{
	*current_piece = *current_piece + 1;
	if (*current_piece > 25 || !(tetrimino[*current_piece].id))
		return (1);
	else
	{
		if (g_optimization == 3)
		{
			if (g_place_pruning[tetrimino[*current_piece].type] != NULL)
				*row = g_place_pruning[tetrimino[*current_piece].type]->row_loc;
			else
				*row = 0;
			if (g_place_pruning[tetrimino[*current_piece].type] != NULL)
				*col = g_place_pruning[tetrimino[*current_piece].type]->col_loc;
			else
				*col = 0;
			*col = *col - 1;
		}
		else
		{
			*col = -1;
			*row = 0;
		}
	}
	return (0);
}
