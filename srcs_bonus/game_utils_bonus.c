/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:31:13 by erantala          #+#    #+#             */
/*   Updated: 2025/05/21 03:53:12 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	ft_set_char_rot(mlx_t *mlx, int rot)
{
	t_data	*data;

	(void)mlx;
	data = get_data();

	ft_char_cords(mlx);
	data->img->char_i->instances->enabled=0;
	data->img->char_l->instances->enabled=0;
	data->img->char_r->instances->enabled=0;
	data->img->char_u->instances->enabled=0;
	if (rot == 1)
		data->img->char_i->instances->enabled=1;
	if (rot == 2)
		data->img->char_l->instances->enabled=1;
	if (rot == 3)
		data->img->char_r->instances->enabled=1;
	if	(rot == 4)
		data->img->char_u->instances->enabled=1;
}

void	ft_char_cords(mlx_t *mlx)
{
	t_data	*data;
	
	(void)mlx;
	data = get_data();
	data->char_cord.y = data->img->char_i->instances->y;
	data->char_cord.x = data->img->char_i->instances->x;
	data->img->char_l->instances->y = data->char_cord.y;
	data->img->char_l->instances->x = data->char_cord.x;
	data->img->char_r->instances->y = data->char_cord.y;
	data->img->char_r->instances->x = data->char_cord.x;
	data->img->char_u->instances->y = data->char_cord.y;
	data->img->char_u->instances->x = data->char_cord.x;
}