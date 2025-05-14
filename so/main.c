/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:41:35 by erantala          #+#    #+#             */
/*   Updated: 2025/05/14 16:52:04 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char		**map;
	int			fd;
	t_point		path;
	int			line_len;
	int			line_count;
	mlx_t		*mlx;
	fd = open("./maps/map_one.ber", O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, "Error opening map", NULL);
	map = get_map(fd, &path);
	if (map)
	{
		line_len = ft_strlen(map[0]);
		line_count = ft_stralen(map);
	}
	create_map(map, line_len, line_count, mlx);
}
