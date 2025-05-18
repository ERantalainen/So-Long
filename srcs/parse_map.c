/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:46:23 by erantala          #+#    #+#             */
/*   Updated: 2025/05/16 14:05:33 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "so_long.h"

char	**get_map(int fd, t_point *path)
{
	char	**map;
	char	*map_line;
	char	*buff_line;
	int		res;

	map_line = (char *)malloc(sizeof(char));
	map_line[0] = '\0';
	buff_line = "";
	while (buff_line)
	{
		buff_line = get_next_line(fd);
		if(!buff_line)
			break;
		map_line = ft_stradd(map_line, buff_line);
		free (buff_line);
	}
	res = check_chars(map_line);
	map = ft_split(map_line, '\n');
	path->y = check_map_valid(map);
	path->x = ft_strlen(map[0]);
	if (!map || map[0] == NULL || res == -1)
		return (NULL);
	res = check_path(map, res, path, map_line);
	free(map_line);
	return (map);
}

int	check_map_valid(char **map)
{
	int	line_count;
	int	line_len;
	int	curr_len;

	line_count = 0;
	line_len = ft_strlen(map[0]);
	if (check_edges(map[line_count]) == -1)
		return (-1);
	while (map[line_count])
	{
		curr_len = ft_strlen(map[line_count]);
		if (curr_len != line_len)
			return (-1);
		if ((map[line_count][0] != '1' || map[line_count][(curr_len -1)] != '1'))
			return (-1);
		line_count++;
	}
	if (check_edges(map[line_count - 1]) == -1)
		return (-1);
	return (line_count);
}

int	check_path(char **map, int spawn, t_point *size, char *map_line)
{
	t_point		spawn_point;
	char		**flood_map;
	int			line_len;
	int			res;

	line_len = ft_strlen(map[0]);
	spawn_point.y = spawn / line_len;
	spawn_point.x = spawn - line_len * spawn_point.y - 1;
	flood_map = ft_stradup(map);
	if (flood_map == NULL)
		return (-1);
	*size = flood_fill(flood_map, *size, spawn_point.y, spawn_point.x);
	if (flood_map[0][2] - '1' != ft_count_char(map_line, 'C'))
		res = -1;
	else if (!(flood_map[0][0] == 'Y' && flood_map[0][1] == 'Y'))
		res = (-1);
	else
		res = 1;
	ft_frearr((void **)flood_map, ft_stralen(flood_map));
	if (res == -1)
	{
		ft_frearr((void **)map, ft_stralen(map));
		ft_exit(NULL, "Invalid map", (void *)map_line);
	}
	return (res);
}

