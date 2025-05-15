/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:27:01 by erantala          #+#    #+#             */
/*   Updated: 2025/05/15 16:53:57 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
	y -= 16;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
		data->img->char_i->instances->y -= pixel / 4;
	if (data->map[y / 64][x / 64] == 'C')
		data->coll -= 1;
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
	x += 16;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
		data->img->char_i->instances->x += pixel / 4;
	if (data->map[y / 64][x / 64] == 'C')
		data->coll -= 1;
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
	x -= 16;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
		data->img->char_i->instances->x -= pixel / 4;
	if (data->map[y / 64][x / 64] == 'C')
		data->coll -= 1;
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
	y += 16;
	if (data->map[y / 64][x / 64] == '1')
		return ;
	else
		data->img->char_i->instances->y += pixel / 4;
	if (data->map[y / 64][x / 64] == 'C')
		data->coll -= 1;
}