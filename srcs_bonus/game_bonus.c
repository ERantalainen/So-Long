/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:39:49 by erantala          #+#    #+#             */
/*   Updated: 2025/05/21 04:32:48 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

int	ft_game_loop(char **map, mlx_t *mlx)
{
	mlx_close_hook(mlx, &ft_close, mlx);
	mlx_loop_hook(mlx, &key_hook, mlx);
	(void)map;
	mlx_loop(mlx);
	ft_exit(mlx, "", NULL);
	return (0);
}

void	key_hook(void *param)
{
	mlx_t		*mlx;
	t_data		*data;
	static int	steps = 0;

	data = get_data();
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		ft_exit(mlx, "", NULL);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		ft_move_up(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		ft_move_down(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		ft_move_left(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		ft_move_right(mlx);
	if (data->coll == 0)
		ft_is_exit(mlx);
	if (steps != data->steps)
	{
		ft_step_print(mlx, steps);
		steps++;
	}
}

void	ft_is_exit(mlx_t *mlx)
{
	t_data	*data;
	int		exit_y;
	int		exit_x;
	int		char_y;
	int		char_x;

	(void)mlx;
	data = get_data();
	exit_y = data->img->exit_i->instances->y;
	exit_x = data->img->exit_i->instances->x;
	char_y = data->char_cord.y;
	char_x = data->char_cord.x;
	if (char_y - exit_y < 10 && char_y - exit_y > -10)
		if (char_x - exit_x < 10 && char_x - exit_x > -10)
			ft_exit(mlx, "", NULL);
}

void	ft_step_print(mlx_t *mlx, int stp)
{
	t_data		*data;
	char		*s;
	int			len;
	int			n;
	int			loop;
	(void)mlx;
	data = get_data();
	n = -1;
	while (++n < 10)
	{
		loop = -1;
		while(++loop < 10)
			data->img->nbr_i[n]->instances[loop].enabled=0;
	}
	s = ft_itoa(data->steps);
	len = ft_strlen(s);
	if (len > 9)
		ft_exit(mlx, "You lost", NULL);
	while (len--)
	{
		data->img->nbr_i[stp % 10]->instances[n].enabled=1;
		data->img->nbr_i[stp % 10]->instances[n--].x = len * 10 + 5;
		stp /= 10;
	}
	free(s);
}
