/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:26:25 by erantala          #+#    #+#             */
/*   Updated: 2025/05/14 16:52:00 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	create_map(char **map, int line_len, int line_count, mlx_t *mlx)
{
	size_t	total;

	if (line_len * 64 > MAX_WIDTH)
		line_len = MAX_WIDTH / 64;
	if (line_count * 64 > MAX_HEIGHT)
		line_count = MAX_HEIGHT / 64;
	total = line_count * line_len * 64;
	mlx = mlx_init(line_len * 64, line_count * 64, "So_Long", true);
	if (!mlx)
	{
		ft_frearr((void **)map, ft_stralen(map));
		ft_exit(NULL, "Error creating window", NULL);
	}
	ft_init_textures(mlx, total, map);

}

void	ft_init_textures(mlx_t *mlx, size_t map_size, char **map)
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
	ft_init_images(mlx, map_size, map, txt);
}

void	ft_init_images(mlx_t *mlx, size_t map_size, char **map, t_txt *textures)
{
	t_images	*images;
	int			err;

	err = 0;
	images->char_i = mlx_texture_to_image(mlx, textures->character);
	if (!images->char_i)
		err = 1;
	images->wall_i = mlx_texture_to_image(mlx, textures->wall);
	if (!images->wall_i)
		err = 1;
	images->coll_i = mlx_texture_to_image(mlx, textures->collectible);
	if (!images->coll_i)
		err = 1;
	images->ground_i = mlx_texture_to_image(mlx, textures->ground);
	if (!images->ground_i)
		err = 1;
	images->exit_i = mlx_texture_to_image(mlx, textures->exit);
	if (!images->exit_i)
		err = 1;
	if (err == 1)
	{
		ft_frearr((void **)map, ft_stralen(map));
		ft_exit(mlx, "Error initializing images", NULL);
	}
	ft_display_images(mlx, map_size, map, images);
}

void	ft_display_images(mlx_t *mlx, size_t map_size, char **map, t_images *images)
{
	ft_background(mlx, map, map_size, images);
	ft_walls(mlx, map, map_size, images);
	ft_center(mlx, map, 'C', images->coll_i);
	ft_center(mlx, map, 'E', images->exit_i);
	ft_center(mlx, map, 'P', images->char_i);
	ft_game_loop(mlx, images, map);
}

