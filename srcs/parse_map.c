/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:46:23 by erantala          #+#    #+#             */
/*   Updated: 2025/06/02 16:12:38 by erantala         ###   ########.fr       */
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
		if (!buff_line)
			break ;
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
	int	count;
	int	len;
	int	c_len;

	count = 0;
	len = ft_strlen(map[0]);
	if (check_edges(map[count]) == -1)
		return (-1);
	while (map[count])
	{
		c_len = ft_strlen(map[count]);
		if (c_len != len)
			return (-1);
		if ((map[count][0] != '1' || map[count][(c_len -1)] != '1'))
			return (-1);
		count++;
	}
	if (check_edges(map[count - 1]) == -1)
		return (-1);
	return (count);
}

int	check_path(char **map, int spawn, t_point *size, char *map_line)
{
	t_point		sp;
	char		**dupe;
	int			line_len;
	int			res;

	line_len = ft_strlen(map[0]);
	sp.y = spawn / line_len;
	sp.x = spawn - line_len * sp.y - 1;
	dupe = ft_stradup(map);
	if (dupe == NULL)
		return (-1);
	if (flood_fill(dupe, *size, sp.y, sp.x) != ft_count_char(map_line, 'C'))
		res = -1;
	else if (!(dupe[0][0] == 'Y' && dupe[0][1] == 'Y'))
		res = (-1);
	else
		res = 1;
	ft_frearr((void **)dupe, ft_stralen(dupe));
	if (res == -1)
	{
		ft_frearr((void **)map, ft_stralen(map));
		ft_exit(NULL, "Invalid map", (void *)map_line);
	}
	return (res);
}
