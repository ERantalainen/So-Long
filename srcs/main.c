/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:41:35 by erantala          #+#    #+#             */
/*   Updated: 2025/05/18 17:38:02 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>

t_images	*ft_init_struct(t_images *img);
int	main(int argc, char **argv)
{
	t_data		*data;
	int			fd;
	t_point		path;
	int			line_len;
	int			line_count;

	(void)argc;
	(void)argv;
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
	create_map(line_len, line_count);
}

t_images	*get_images()
{
	static t_images	*img;
	
	if (img == NULL)
		img = ft_init_struct(img);
	return (img);
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
	{
		count += ft_count_char(data->map[row], 'C');
		row++;
	}
	data->coll = count;
	img = malloc(sizeof(t_images));
	img->char_i = NULL;
	img->wall_i = NULL;
	img->exit_i = NULL;
	img->ground_i = NULL;
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

void	ft_free_struct(mlx_image_t **data, int row)
{
	while(row)
	{
		free(data[row]);
	}
	free (data);
	ft_exit(NULL, "Malloc error", NULL);
}