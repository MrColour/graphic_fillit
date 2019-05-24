/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:38:58 by kmira             #+#    #+#             */
/*   Updated: 2019/05/23 15:16:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "fillit_structs.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdint.h>

#include <stdio.h>

/*
** Top Section needs to be added to a place in libft.h
*/

# include <errno.h>

# define INVALID_FILE -1

/*
** This counts as two lines of code and is potentially dangerous/difficult to
** catch why an else statement might be expecting an expression.
** I would recommend making this a standalone function and just calling that.
*/

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

# define ERROR()

/*
** ------------------------------END-------------------------------------
*/

# define MAX_BOARD_SIZE 16
# define MAX_TETRIMINO_PIECES 26
# define MAX_FILE_BYTES 546

# define PIECE_LEN 20

/*
** Found in file:
**		input.c
*/

int		begin_reading(int fd, t_tetrimino *tetrimino);
int		input_sanitized(char *file_buff, int bytes_read, t_tetrimino *tetrim);
int		piece_sanitized(char *piece_buffer, int bytes_remaining);

int		isvalid_chars(char *buffer);
int		isfully_connected(char *buffer);

/*
** Found in file:
**		encoding.c
*/

void	encode_piece(char *buffer, t_tetrimino *tetrimino, int piece_index);

/*
** Found in file:
**		solver.c
*/

int		count_pieces(t_tetrimino *tetrimino);
int		fill_board_with(t_tetrimino *tetriminos);

/*
** Found in file:
**		output.c
*/

void	write_piece(t_tetrimino piece, char *board_str, int board_size);
void	print_solution_of
	(t_tetrimino *tetriminos, int board_size, int current_piece);
void	final_print(t_tetrimino *tetriminos, int board_size, int current_piece);

/*
** Found in file:
**		solving_utils.c
*/

void	place_piece
	(t_tetrimino *tetrimino, unsigned short *board, int *row, int *col);
void	remove_piece
	(t_tetrimino tetrimino, unsigned short *board, int *row, int *col);
int		board_is_solved
	(int *current_piece, t_tetrimino *tetrimino, int *row, int *col);

#endif
