/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_sanitization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:26:13 by kmira             #+#    #+#             */
/*   Updated: 2019/05/13 14:32:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define HASHES 0
#define DOTS 1
#define NEW_LINES 2
#define OTHERS 3

int		index_of(char c)
{
	if (c == '#')
		return (HASHES);
	else if (c == '.')
		return (DOTS);
	else
		return (OTHERS);
}

int		new_line_checker(char *buffer)
{
	int		result;

	result = 0;
	if (buffer[4] == '\n')
		result++;
	if (buffer[9] == '\n')
		result++;
	if (buffer[14] == '\n')
		result++;
	if (buffer[19] == '\n')
		result++;
	return (result);
}

int		isvalid_chars(char *buffer)
{
	int	i;
	int	expected[4];

	i = 0;
	expected[HASHES] = 4;
	expected[DOTS] = 12;
	expected[NEW_LINES] = 4;
	expected[OTHERS] = 0;
	while (i < 4 && expected[OTHERS] == 0)
	{
		expected[index_of(buffer[i + 0])] += -1;
		expected[index_of(buffer[i + 5])] += -1;
		expected[index_of(buffer[i + 10])] += -1;
		expected[index_of(buffer[i + 15])] += -1;
		i++;
	}
	expected[NEW_LINES] += -new_line_checker(buffer);
	if (expected[HASHES] == 0 &&
		expected[DOTS] == 0 &&
		expected[NEW_LINES] == 0 &&
		expected[OTHERS] == 0)
		return (1);
	else
		return (-1);
}

/*
** A flood fill type of Algorithm would be needed in order to do this correctly.
** It would latch onto the first hash and go from there.
*/

int		isfully_connected(char *buffer)
{
	int i;
	int connections;

	i = 0;
	connections = 0;
	while (i < 20)
	{
		if (buffer[i] == '#')
		{
			if (i % 5 > 0 && buffer[i - 1] == '#')
				connections++;
			if (i % 5 < 4 && buffer[i + 1] == '#')
				connections++;
			if (i - 5 > -1 && buffer[i - 5] == '#')
				connections++;
			if (i + 5 < 20 && buffer[i + 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	else
		return (-1);
}
