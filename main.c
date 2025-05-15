/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:41:35 by erantala          #+#    #+#             */
/*   Updated: 2025/05/15 16:50:03 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
t_images	*ft_init_struct();
int	main(int argc, char **argv)
{
	t_data		*data;
	int			fd;
	t_point		path;
	int			line_len;
	int			line_count;
	mlx_t		*mlx;

	data = get_data();
	fd = open("./maps/map_one.ber", O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, "Error opening map", NULL);
	data->map = get_map(fd, &path);
	if (data->map)
	{
		line_len = ft_strlen(data->map[0]);
		line_count = ft_stralen(data->map);
	}
	data->img = get_images();
	create_map(data->map, line_len, line_count, mlx);
}

t_images	*get_images()
{
	static t_images	*img;
	if (img == NULL)
		img = ft_init_struct();
	return (img);
}

t_images	*ft_init_struct()
{
	t_images	*img;

	img = malloc(sizeof(t_images) * 5);
	img->char_i = malloc(sizeof(mlx_image_t *));
	img->wall_i = malloc(sizeof(mlx_image_t *));
	img->coll_i = malloc(sizeof(mlx_image_t *));
	img->exit_i = malloc(sizeof(mlx_image_t * ));
	img->ground_i = malloc(sizeof(mlx_image_t *));
	return (img);
}