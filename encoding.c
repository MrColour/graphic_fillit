/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:40:28 by kmira             #+#    #+#             */
/*   Updated: 2019/05/20 14:20:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "piece.h"

static void	align_piece(unsigned short *mask)
{
	int				i;
	unsigned short	left_boundary;
	unsigned short	top_boundary;

	i = 0;
	left_boundary = 0b1000000000000000;
	top_boundary = 0b1111000000000000;
	while (i < 4)
	{
		if ((mask[0] & left_boundary) == 0 &&
			(mask[1] & left_boundary) == 0 &&
			(mask[2] & left_boundary) == 0 &&
			(mask[3] & left_boundary) == 0)
		{
			mask[0] = mask[0] << 1;
			mask[1] = mask[1] << 1;
			mask[2] = mask[2] << 1;
			mask[3] = mask[3] << 1;
		}
		if ((mask[0] & top_boundary) == 0)
			*(u_int64_t *)mask = ((*(u_int64_t *)mask) >> 16);
		i++;
	}
}

static void	set_mask(char *buffer, unsigned short *tetrimino_mask)
{
	int				i;
	unsigned short	mask;

	i = 0;
	mask = 0b1000000000000000;
	tetrimino_mask[0] = 0;
	tetrimino_mask[1] = 0;
	tetrimino_mask[2] = 0;
	tetrimino_mask[3] = 0;
	while (i < 4)
	{
		if (buffer[i + 0] == '#')
			tetrimino_mask[0] ^= mask;
		if (buffer[i + 5] == '#')
			tetrimino_mask[1] ^= mask;
		if (buffer[i + 10] == '#')
			tetrimino_mask[2] ^= mask;
		if (buffer[i + 15] == '#')
			tetrimino_mask[3] ^= mask;
		mask = mask >> 1;
		i++;
	}
	align_piece(tetrimino_mask);
}

static void	classify_piece(t_tetrimino *tetrimino, int piece_index)
{
	int				i;
	unsigned short	*mask;

	i = 0;
	mask = tetrimino[piece_index].mask;
	while (i < 19)
	{
		if (g_piece_classifier[i][0] == mask[0] &&
			g_piece_classifier[i][1] == mask[1] &&
			g_piece_classifier[i][2] == mask[2] &&
			g_piece_classifier[i][3] == mask[3])
		{
			tetrimino[piece_index].type = g_piece_classifier[i][4];
			tetrimino[piece_index].height = g_piece_classifier[i][5];
			tetrimino[piece_index].width = g_piece_classifier[i][6];
			break ;
		}
		i++;
	}
}

void		encode_piece(char *buffer, t_tetrimino *tetrimino, int piece_index)
{
	set_mask(buffer, tetrimino[piece_index].mask);
	classify_piece(tetrimino, piece_index);
	tetrimino[piece_index].last = NULL;
	tetrimino[piece_index].color1 = '1' + (piece_index % 6);
	tetrimino[piece_index].row_loc = 0;
	tetrimino[piece_index].col_loc = 0;
	tetrimino[piece_index].id = 219;
}
