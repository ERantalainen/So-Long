/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:50:25 by erantala          #+#    #+#             */
/*   Updated: 2025/05/20 16:44:11 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	ft_init_char_txt(mlx_t *mlx, t_txt *txt)
{
	txt->char_left = mlx_load_png("./textures/CharLeft.png");
	if (!txt->char_left)
		ft_exit(mlx, "Error initializing images", NULL);
	txt->char_up = mlx_load_png("./textures/CharUp.png");
	if (!txt->char_up)
		ft_exit(mlx, "Error initializing images", NULL);
	txt->char_right = mlx_load_png("./textures/CharRight.png");
	if (!txt->char_right)
		ft_exit(mlx, "Error initializing images", NULL);
	txt->character = mlx_load_png("./textures/Char.png");
	if (!txt->character)
		ft_exit(mlx, "Error initializing images", NULL);
}

void	ft_init_char_img(mlx_t *mlx, t_txt *txt, t_images *img)
{
	if (!(img->char_i = mlx_texture_to_image(mlx, txt->character)))
		ft_exit(mlx, "Error initializing images", NULL);
	if (!(img->char_l = mlx_texture_to_image(mlx, txt->char_left)))
		ft_exit(mlx, "Error initializing images", NULL);
	if (!(img->char_r = mlx_texture_to_image(mlx, txt->char_right)))
		ft_exit(mlx, "Error initializing images", NULL);
	if (!(img->char_u = mlx_texture_to_image(mlx, txt->char_up)))
		ft_exit(mlx, "Error initializing images", NULL);
}
