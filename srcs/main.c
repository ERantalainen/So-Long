/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:41:35 by erantala          #+#    #+#             */
/*   Updated: 2025/05/19 19:20:21 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	int			fd;
	t_point		path;
	int			line_len;
	int			line_count;

	line_len = 0;
	line_count = 0;
	fd = ft_valid_input(argc, argv);
	data = get_data();
	data->map = get_map(fd, &path);
	if (data->map != NULL)
	{
		line_len = ft_strlen(data->map[0]);
		line_count = ft_stralen(data->map);
	}
	else
		ft_exit(NULL, "Error parsing map", NULL);
	data->img = get_images();
	create_map(line_len, line_count);
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
