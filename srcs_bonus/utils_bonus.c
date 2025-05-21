/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:50:25 by erantala          #+#    #+#             */
/*   Updated: 2025/05/21 04:29:04 by erantala         ###   ########.fr       */
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
void	ft_init_nbr_txt(mlx_t *mlx, t_txt *txt)
{
	int	n;
	const char	*end = ".png";
	const char	*pre = "./numbers/";
	char	*path;
	char	*nbr_s;
	
	n = 0;
	while(n < 10)
	{
		txt->nbr[n] = malloc(sizeof(mlx_texture_t));
		if (!txt->nbr[n])
			ft_exit(mlx, "Malloc error", NULL);
		nbr_s = ft_itoa(n);
		path = ft_strjoin(pre, nbr_s);
		free(nbr_s);
		path = ft_stradd(path, end);
		if(!path)
			ft_exit(mlx, "Malloc error", NULL);
		if(!(txt->nbr[n] = mlx_load_png(path)))
			ft_exit(mlx, "Error initializing images", path);
		free(path);
		n++;
	}
}

void	ft_init_nbr_img(mlx_t *mlx, t_txt *txt, t_images *img)
{
	int	n;
	int	loop;

	n = 0;
	while(n < 10)
	{
		loop = 0;
		while (loop < 4)
		{
			if (!(img->nbr_i[n] = mlx_texture_to_image(mlx, txt->nbr[n])))
				ft_exit(mlx, "Error initializing images", NULL);
			loop++;
		}
		n++;
	}
}

void	ft_display_img(mlx_t *mlx)
{
	t_data	*data;
	int		n;
	int		er;
	int		loop;

	data = get_data();
	n = 0;
	while (n < 10)
	{
		loop = -1;
		while (++loop < 10)
		{
		er = mlx_image_to_window(mlx, data->img->nbr_i[n], 0, 15);
		if (er < 0)
			ft_exit(mlx, "Error displaying images", NULL);
		data->img->nbr_i[n]->instances[loop].enabled=0;
		}
		n++;
	}
}
