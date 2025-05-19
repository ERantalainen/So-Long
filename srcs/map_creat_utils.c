/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:51:59 by erantala          #+#    #+#             */
/*   Updated: 2025/05/19 16:48:05 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"
#include "libft.h"

int	ft_find_target(char *map, char target)
{
	size_t	pos;
	int		count;

	count = -1;
	pos = 0;
	while (map[pos])
	{
		if (target == map[pos])
			count++;
		pos++;
	}
	return (count);
}

void	ft_background(mlx_t *mlx, size_t map_size, t_images *images)
{
	int		row_max;
	int		col_max;
	int		col;
	t_data	*data;

	data = get_data();
	row_max = map_size / ft_strlen(data->map[0]) * 64;
	col_max = map_size / ft_stralen(data->map);
	while (row_max >= 0)
	{
		col = col_max;
		while (col >= 0)
		{
			if (mlx_image_to_window(mlx, images->ground_i, row_max, col) < 0)
				ft_exit(mlx, "Error displaying images", NULL);
			col -= 32;
		}
		row_max -= 32;
	}
}

void	ft_walls(mlx_t *mlx, t_images *img)
{
	size_t	rw;
	size_t	cl;
	int		tp;
	t_data	*data;

	data = get_data();
	rw = 0;
	cl = 0;
	while (rw < ft_strlen(data->map[0]))
	{
		cl = 0;
		while (cl < ft_stralen(data->map))
		{
			if (data->map[cl][rw] == '1')
				tp = mlx_image_to_window(mlx, img->wall_i, rw * 64, cl * 64);
			if (tp < 0)
			{
				ft_frearr((void **)data->map, ft_stralen(data->map));
				ft_exit(mlx, "Error creating map", NULL);
			}
			cl++;
		}
		rw++;
	}
}

void	ft_center(mlx_t *mlx, char **map, char target, mlx_image_t *img)
{
	size_t	cl;
	size_t	rw;
	size_t	x;
	size_t	y;

	rw = 0;
	while (rw < ft_strlen(map[0]))
	{
		cl = 0;
		while (cl < ft_stralen(map))
		{
			y = (rw * 64) + 22;
			x = (cl * 64) + 22;
			if (map[cl][rw] == target)
			{
				mlx_image_to_window(mlx, img, y, x);
				return ;
			}
			cl++;
		}
		rw++;
	}
}

void	ft_collectibles(mlx_t *mlx, char **map, t_images *img)
{
	int	row;
	int	col;
	int	i;
	int	x;
	int	y;

	row = 1;
	i = 0;
	while (map[row])
	{
		col = 1;
		while (map[row][col])
		{
			if (map[row][col] == 'C')
			{
				x = row * 64 + 20;
				y = col * 64 + 20;
				if ((mlx_image_to_window(mlx, img->coll_i[i], y, x)) < 0)
					ft_exit(mlx, "Error placing collectibles", NULL);
				i++;
			}
			col++;
		}
		row++;
	}
}
