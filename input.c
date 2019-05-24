/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:12:49 by kmira             #+#    #+#             */
/*   Updated: 2019/05/14 17:12:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	piece_sanitized(char *piece_buffer, int bytes_remaining)
{
	if (bytes_remaining >= PIECE_LEN)
	{
		if (isvalid_chars(piece_buffer) == -1)
			return (-1);
		else if (isfully_connected(piece_buffer) == -1)
			return (-1);
		else
			return (1);
	}
	else
		return (-1);
}

/*
** Buffer needs one index more to store one above the max size,
** then another for the NULL character.
*/

int	input_sanitized(char *file_buff, int bytes_read, t_tetrimino *tetrimino)
{
	int	bytes_sanitized;
	int	bytes_remaining;
	int	piece_index;

	bytes_sanitized = 0;
	piece_index = 0;
	while (bytes_sanitized < bytes_read)
	{
		bytes_remaining = bytes_read - bytes_sanitized;
		if (piece_sanitized(&file_buff[bytes_sanitized], bytes_remaining) != -1)
			encode_piece(&file_buff[bytes_sanitized], tetrimino, piece_index++);
		else
			return (-1);
		bytes_sanitized = bytes_sanitized + PIECE_LEN;
		if (file_buff[bytes_sanitized] == '\0')
			break ;
		else if (file_buff[bytes_sanitized] == '\n')
			bytes_sanitized = bytes_sanitized + 1;
		else
			return (-1);
	}
	bytes_remaining = bytes_read - bytes_sanitized;
	if (bytes_remaining == 0)
		return (1);
	return (-1);
}

/*
** buffer[bytes_read] ensures no garbage values will be read
*/

int	begin_reading(const int fd, t_tetrimino *tetrimino)
{
	char	buffer[MAX_FILE_BYTES + 2];
	int		bytes_read;

	bytes_read = read(fd, buffer, MAX_FILE_BYTES + 1);
	close(fd);
	buffer[bytes_read] = '\0';
	if (bytes_read > MAX_FILE_BYTES)
	{
		errno = INVALID_FILE_FORMAT;
		return (-1);
	}
	else if (bytes_read <= 0)
		return (-1);
	else if (input_sanitized(buffer, bytes_read, tetrimino) == -1)
	{
		errno = INVALID_PIECE_FORMAT;
		return (-1);
	}
	else
		return (1);
}
