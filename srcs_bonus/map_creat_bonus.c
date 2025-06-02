/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:26:25 by erantala          #+#    #+#             */
/*   Updated: 2025/06/02 17:01:39 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	create_map(int line_len, int line_count)
{
	size_t	total;
	t_data	*data;
	mlx_t	*mlx;

	data = get_data();
	total = line_count * line_len * 64;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(line_len * 64, line_count * 64, "So_Long", true);
	if (!mlx)
		ft_exit(NULL, "Error creating window", NULL);
	mlx_set_window_limit(mlx, 100, 100, MAX_WIDTH, MAX_HEIGHT);
	data->mlx = mlx;
	ft_init_textures(total, mlx);
}

void	ft_init_textures(size_t map_size, mlx_t *mlx)
{
	t_txt	*txt;

	txt = malloc(sizeof(t_txt));
	if (!txt)
		ft_exit(mlx, "Malloc error", NULL);
	txt->nbr = malloc(sizeof(mlx_texture_t *) * 10);
	if (!txt->nbr)
		ft_exit(mlx, "Malloc error", NULL);
	txt->ground = mlx_load_png("./textures/Grass.png");
	if (!txt->ground)
		ft_exit(mlx, "Error initializing images", NULL);
	txt->wall = mlx_load_png("./textures/Hills.png");
	if (!txt->wall)
		ft_exit(mlx, "Error initializing images", NULL);
	txt->coll = mlx_load_png("./textures/Collectible.png");
	if (!txt->coll)
		ft_exit(mlx, "Error initializing images", NULL);
	txt->exit = mlx_load_png("./textures/Exit.png");
	if (!txt->exit)
		ft_exit(mlx, "Error initializing images", NULL);
	ft_init_char_txt(mlx, txt);
	ft_init_nbr_txt(mlx, txt);
	ft_init_images(map_size, txt, mlx);
}

void	ft_init_images(size_t map_size, t_txt *textures, mlx_t *mlx)
{
	t_data		*data;
	t_images	*img;

	data = get_data();
	img = data->img;
	img->wall_i = mlx_texture_to_image(mlx, textures->wall);
	if (!img->wall_i)
		ft_exit(mlx, "Error initializing images", NULL);
	img->ground_i = mlx_texture_to_image(mlx, textures->ground);
	if (!img->ground_i)
		ft_exit(mlx, "Error initializing images", NULL);
	img->exit_i = mlx_texture_to_image(mlx, textures->exit);
	if (!img->exit_i)
		ft_exit(mlx, "Error initializing images", NULL);
	img->text = mlx_put_string(mlx, "0", 20, 20);
	if (!img->text)
		ft_exit(mlx, "Error initializing images", NULL);
	ft_init_char_img(mlx, textures, img);
	ft_init_nbr_img(mlx, textures, img);
	ft_init_coll(textures, mlx);
	ft_display_images(map_size, img, mlx);
}

void	ft_display_images(size_t size, t_images *img, mlx_t *mlx)
{
	t_data	*data;

	data = get_data();
	ft_background(mlx, size, img);
	ft_walls(mlx, img);
	ft_collectibles(mlx, data->map, img);
	ft_center(mlx, data->map, 'E', img->exit_i);
	ft_center(mlx, data->map, 'P', img->char_i);
	ft_center(mlx, data->map, 'P', img->char_l);
	ft_center(mlx, data->map, 'P', img->char_r);
	ft_center(mlx, data->map, 'P', img->char_u);
	ft_set_char_rot(1);
	ft_display_img(mlx);
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
