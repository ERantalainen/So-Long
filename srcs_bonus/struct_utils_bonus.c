/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:50:09 by erantala          #+#    #+#             */
/*   Updated: 2025/05/20 18:04:39 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

t_images	*get_images(void)
{
	static t_images	*img;
	int				nbr;

	nbr = 0;
	if (img == NULL)
	{
		img = ft_init_struct(img);
		img->char_i = NULL;
		img->wall_i = NULL;
		img->exit_i = NULL;
		img->ground_i = NULL;
		img->char_l = NULL;
		img->char_r = NULL;
		img->char_u = NULL;
		img->nbr_i = malloc(sizeof(mlx_image_t *) * 10);
		if (!img->nbr_i)
			ft_exit(NULL, "Error mallocing struct", NULL);
		while(nbr++ < 9)
		{
			img->nbr_i[nbr] = malloc(sizeof(mlx_image_t));
			if	(!img->nbr_i[nbr])
				ft_exit(NULL, "Error mallocing struct", NULL);
		}
	}
	return (img);
}

t_data	*get_data(void)
{
	static t_data	*data;

	if (data == NULL)
		data = ft_init_data();
	return (data);
}

t_data	*ft_init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = NULL;
	data->map = NULL;
	data->coll = 0;
	data->mlx = NULL;
	data->char_cord.x = 0;
	data->char_cord.y = 0;
	data->steps = 0;
	return (data);
}

t_images	*ft_init_struct(t_images *img)
{
	t_data	*data;
	int		row;
	int		count;

	count = 0;
	row = 0;
	data = get_data();
	while (data->map[row])
		count += ft_count_char(data->map[row++], 'C');
	data->coll = count;
	img = malloc(sizeof(t_images));
	if (!img)
		return (NULL);
	img->coll_i = malloc(sizeof(mlx_image_t*) * count);
	if (!img->coll_i)
		return (NULL);
	row = 0;
	while (row < count)
	{
		img->coll_i[row] = malloc(sizeof(mlx_image_t));
		if(!img->coll_i[row])
			ft_free_struct(img->coll_i, row);
		row++;
	}
	return (img);
}
void	free_data(void)
{
	t_data	*data;

	data = get_data();
	if (data->map != NULL)
		ft_frearr((void **)data->map, ft_stralen(data->map));
	else
		free(data->map);
	close(data->fd);
	free(data);
}