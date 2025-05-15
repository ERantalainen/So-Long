/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:53:50 by erantala          #+#    #+#             */
/*   Updated: 2025/05/14 15:05:20 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	check_edges(char *line)
{
	int		len;
	char	*comp;
	int		res;

	len  = ft_strlen(line);
	comp = (char *)malloc(sizeof(char) * len);
	ft_memset(comp, '1', len);
	if (ft_memcmp(line, comp, len) != 0)
		res = -1;
	else
		res = 1;
	free(comp);
	return (res);
}

int	check_chars(char *map_line)
{
	int		stat[5];
	char	c;

	stat[4] = 0;
	while (map_line[stat[4]])
	{
		c = map_line[stat[4]++];
		if (!((c == '0' || c == '1'|| c == 'C')
		|| (c == 'E' || c == 'P') || c == '\n'))
			return (-1);
		if (c == 'P')
			stat[3] = stat[4] - 1;
	}
	stat[0] = ft_count_char(map_line, 'P');
	stat[1] = ft_count_char(map_line, 'P');
	stat[2] = ft_count_char(map_line, 'C');
	if (stat[0] != 1 || stat[1] != 1 || !(stat[2] >= 1))
		return (-1);
	return (stat[3]);
}

t_point	flood_fill(char **map, t_point size, int row, int col)
{
	t_point	pos;

	pos.y = row;
	pos.x = col;
	if (map[row][col] == 'E')
	{
		map[0][0] = 'Y';
		return (pos);
	}
	if (map[row][col] == 'C')
	{
		map[0][1] = 'Y';
		map[0][2] += 1;
	}
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return (pos);
	if (map[row][col] == 'V' || check_fill_char((map[row][col])))
		return (pos);
	map[row][col] = 'V';
	flood_fill(map, size, row + 1, col);
	flood_fill(map, size, row - 1, col);
	flood_fill(map, size, row, col + 1);
	flood_fill(map, size, row, col - 1);
	return (pos);
}

int	check_fill_char(char c)
{
	if (c == 'C' || c == '0' || c == 'P')
		return (0);
	else
		return (1);
}

size_t ft_count_char(char *s, char c)
{
	size_t	pos;
	size_t	count;

	count = 0;
	pos = 0;
	if (!s)
		return (0);
	while (s[pos])
	{
		if (s[pos] == c)
			count++;
		pos++;
	}
	return (count);
}