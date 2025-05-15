/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:26:25 by erantala          #+#    #+#             */
/*   Updated: 2025/05/15 16:58:10 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"



void	create_map(char **map, int line_len, int line_count, mlx_t *mlx)
{
	size_t	*total;
	t_data	*data;
	int		row;

	row = 0;
	if (line_len * 64 > MAX_WIDTH)
		line_len = MAX_WIDTH / 64;
	if (line_count * 64 > MAX_HEIGHT)
		line_count = MAX_HEIGHT / 64;
	*total = line_count * line_len * 64;
	mlx = mlx_init(line_len * 64, line_count * 64, "So_Long", true);
	if (!mlx)
	{
		ft_frearr((void **)map, ft_stralen(map));
		ft_exit(NULL, "Error creating window", NULL);
	}
	ft_init_textures(*total, map, mlx);
}

void	ft_init_textures(size_t map_size, char **map, mlx_t *mlx)
{
	t_txt	*txt;
	int err;

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
	txt->collectible = mlx_load_png("./textures/Collectible.png");
	if (!txt->collectible)
		err = 1;
	txt->exit = mlx_load_png("./textures/Exit.png");
	if (!txt->exit)
		err = 1;
	if (err == 1)
	{
		ft_frearr((void **)map, ft_stralen(map));
		ft_exit(mlx, "Error initializing images", NULL);
	}
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
	img->coll_i = mlx_texture_to_image(mlx, textures->collectible);
	if (!img->coll_i)
		err = 1;
	img->ground_i = mlx_texture_to_image(mlx, textures->ground);
	if (!img->ground_i)
		err = 1;
	img->exit_i = mlx_texture_to_image(mlx, textures->exit);
	if (!img->exit_i)
		err = 1;
	if (err == 1)
		ft_exit(mlx, "Error initializing images", NULL);
	ft_display_images(map_size, map, img, mlx);
}

void	ft_display_images(size_t map_size, char **map, t_images *images, mlx_t *mlx)
{
	ft_background(mlx, map, map_size, images);
	ft_walls(mlx, map, map_size, images);
	ft_center(mlx, map, 'C', images->coll_i);
	ft_center(mlx, map, 'E', images->exit_i);
	ft_center(mlx, map, 'P', images->char_i);
	ft_game_loop(map, mlx);
}

int	ft_game_loop(char **map, mlx_t *mlx)
{
	mlx_close_hook(mlx, ft_close(mlx, NULL), NULL);
	mlx_loop_hook(mlx, &key_hook, mlx);
	mlx_loop(mlx);
	ft_frearr((void **)map, ft_stralen(map));
	ft_exit(mlx, "", NULL);
	return (0);
}

void	key_hook(void *param)
{
	mlx_t	*mlx;
	t_images	*img;
	t_data		*data;

	data = get_data();
	img = get_images();
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
	ft_printf("%d", data->coll);
}