/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:51:57 by erantala          #+#    #+#             */
/*   Updated: 2025/05/20 18:42:22 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	ft_move_up(mlx_t *mlx)
{
	t_data		*data;
	int			x;
	int			y;
	int			pixel;
	size_t		size;

	data = get_data();
	x = data->img->char_i->instances->x;
	y = data->img->char_i->instances->y;
	size = ft_strlen(data->map[0]) * ft_stralen(data->map) * 64;
	if (size > MAX_HEIGHT * MAX_WIDTH)
		pixel = MAX_HEIGHT * MAX_WIDTH / 64;
	else
		pixel = 64;
	y -= 32;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
	{
		data->img->char_i->instances->y -= pixel / 4;
		data->steps++;
	}
	if (data->map[y / 64][x / 64] == 'C')
		data->coll += ft_get_cords(mlx, data->map, x, y);
}

void	ft_move_right(mlx_t *mlx)
{
	t_data		*data;
	int			x;
	int			y;
	int			pixel;
	size_t		size;

	data = get_data();
	x = data->img->char_i->instances->x;
	y = data->img->char_i->instances->y;
	size = ft_strlen(data->map[0]) * ft_stralen(data->map) * 64;
	if (size > MAX_HEIGHT * MAX_WIDTH)
		pixel = MAX_HEIGHT * MAX_WIDTH / 64;
	else
		pixel = 64;
	x += 32;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
	{
		data->img->char_i->instances->x += pixel / 4;
		data->steps++;
	}
	if (data->map[y / 64][x / 64] == 'C')
		data->coll += ft_get_cords(mlx, data->map, x, y);
}

void	ft_move_left(mlx_t *mlx)
{
	t_data		*data;
	int			x;
	int			y;
	int			pixel;
	size_t		size;

	data = get_data();
	x = data->img->char_i->instances->x;
	y = data->img->char_i->instances->y;
	size = ft_strlen(data->map[0]) * ft_stralen(data->map) * 64;
	if (size > MAX_HEIGHT * MAX_WIDTH)
		pixel = MAX_HEIGHT * MAX_WIDTH / 64;
	else
		pixel = 64;
	x -= 32;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
	{
		data->img->char_i->instances->x -= pixel / 4;
		data->steps++;
	}
	if (data->map[y / 64][x / 64] == 'C')
		data->coll += ft_get_cords(mlx, data->map, x, y);
}

void	ft_move_down(mlx_t *mlx)
{
	t_data		*data;
	int			x;
	int			y;
	int			pixel;
	size_t		size;

	data = get_data();
	x = data->img->char_i->instances->x;
	y = data->img->char_i->instances->y;
	size = ft_strlen(data->map[0]) * ft_stralen(data->map) * 64;
	if (size > MAX_HEIGHT * MAX_WIDTH)
		pixel = MAX_HEIGHT * MAX_WIDTH / 64;
	else
		pixel = 64;
	y += 32;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
	{
		data->img->char_i->instances->y += pixel / 4;
		data->steps++;
	}
	y = data->img->char_i->instances->y;
	if (data->map[y / 64][x / 64] == 'C')
		data->coll += ft_get_cords(mlx, data->map, x, y);
}

int	ft_get_cords(mlx_t *mlx, char **map, int x, int y)
{
	size_t	row;
	size_t	col;
	int		count;
	t_data	*data;

	data = get_data();
	col = 0;
	count = 0;
	while (col++ < ft_stralen(map))
	{
		row = 0;
		while (row++ < ft_strlen(map[0]))
		{
			if (map[col][row] == 'C' || map[col][row] == 'A')
				count++;
			if ((int)col == y / 64 && (int)row == x / 64)
			{
				mlx_delete_image(mlx, data->img->coll_i[count -1]);
				data->img->coll_i[count -1] = NULL;
				map[col][row] = 'A';
				return (-1);
			}
		}
	}
	return (0);
}