/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:26:25 by erantala          #+#    #+#             */
/*   Updated: 2025/05/19 19:27:59 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	create_map(int line_len, int line_count)
{
	size_t	total;
	t_data	*data;
	mlx_t	*mlx;

	data = get_data();
	if (line_len * 64 > MAX_WIDTH)
		line_len = MAX_WIDTH / 64;
	if (line_count * 64 > MAX_HEIGHT)
		line_count = MAX_HEIGHT / 64;
	total = line_count * line_len * 64;
	mlx = mlx_init(line_len * 64, line_count * 64, "So_Long", true);
	if (!mlx)
		ft_exit(NULL, "Error creating window", NULL);
	data->mlx = mlx;
	ft_init_textures(total, data->map, mlx);
}

void	ft_init_textures(size_t map_size, char **map, mlx_t *mlx)
{
	t_txt	*txt;
	int		err;

	txt = malloc(sizeof(t_txt));
	err = 0;
	txt->ground = mlx_load_png("./textures/Grass.png");
	if (!txt->ground)
		err = 1;
	txt->character = mlx_load_png("./textures/Char.png");
	if (!txt->character)
		err = 1;
	txt->wall = mlx_load_png("./textures/Hills.png");
	if (!txt->wall)
		err = 1;
	txt->coll = mlx_load_png("./textures/Collectible.png");
	if (!txt->coll)
		err = 1;
	txt->exit = mlx_load_png("./textures/Exit.png");
	if (!txt->exit)
		err = 1;
	if (err == 1)
		ft_exit(mlx, "Error initializing images", NULL);
	ft_init_images(map_size, map, txt, mlx);
}

void	ft_init_images(size_t map_size, char **map, t_txt *textures, mlx_t *mlx)
{
	int			err;
	t_images	*img;

	img = get_images();
	err = 0;
	img->char_i = mlx_texture_to_image(mlx, textures->character);
	if (!img->char_i)
		err = 1;
	img->wall_i = mlx_texture_to_image(mlx, textures->wall);
	if (!img->wall_i)
		err = 1;
	img->ground_i = mlx_texture_to_image(mlx, textures->ground);
	if (!img->ground_i)
		err = 1;
	img->exit_i = mlx_texture_to_image(mlx, textures->exit);
	if (!img->exit_i)
		err = 1;
	if (err == 1)
		ft_exit(mlx, "Error initializing images", NULL);
	ft_init_coll(textures, mlx);
	ft_display_images(map_size, map, img, mlx);
}

void	ft_display_images(size_t size, char **map, t_images *img, mlx_t *mlx)
{
	t_data	*data;

	(void)map;
	data = get_data();
	ft_background(mlx, size, img);
	ft_walls(mlx, img);
	ft_collectibles(mlx, data->map, img);
	ft_center(mlx, data->map, 'E', img->exit_i);
	ft_center(mlx, data->map, 'P', img->char_i);
	ft_game_loop(data->map, mlx);
}

void	ft_init_coll(t_txt *txt, mlx_t *mlx)
{
	t_data	*data;
	int		col;
	int		row;
	int		i;

	i = 0;
	row = 0;
	data = get_data();
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'C')
			{
				data->img->coll_i[i] = mlx_texture_to_image(mlx, txt->coll);
				if (!data->img->coll_i[i])
					ft_exit(mlx, "Error initializing images", NULL);
				i++;
			}
			col++;
		}
		row++;
	}
	data->coll_c = i;
}

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
	mlx_t	*mlx;
	t_data	*data;

	data = get_data();
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		ft_exit(mlx, "", NULL);
		mlx_close_window(mlx);
	}
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
	ft_printf("%d\n", data->steps);
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
	char_y = data->img->char_i->instances->y;
	char_x = data->img->char_i->instances->x;
	if (char_y - exit_y < 10 && char_y - exit_y > -10)
		if (char_x - exit_x < 10 && char_x - exit_x > -10)
			ft_exit(mlx, "", NULL);
}
