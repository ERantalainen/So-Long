/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:57:27 by erantala          #+#    #+#             */
/*   Updated: 2025/05/19 19:28:41 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <fcntl.h>

void	ft_exit(mlx_t *mlx, const char *s, void *fre)
{
	int		res;

	free_data();
	if (mlx && (!s[0]))
	{
		mlx_terminate(mlx);
		res = EXIT_SUCCESS;
	}
	else if (mlx != NULL)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd((char *)s, 2);
		mlx_terminate(mlx);
		res = EXIT_FAILURE;
	}
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd((char *)s, 2);
		free (fre);
		res = EXIT_FAILURE;
	}
	exit(res);
}

void	ft_close(void *param)
{
	if (!param)
		ft_exit(NULL, "", NULL);
	else
		ft_exit(param, "", NULL);
}

void	free_data(void)
{
	t_data	*data;

	data = get_data();
	if (data->map != NULL)
	{
		ft_frearr((void **)data->map, ft_stralen(data->map));
	}
	else
		free(data->map);
	free(data);
}
int	ft_valid_input(int argc, char **argv)
{
	int			fd;
	const char	*s = "./maps/";
	char		*map;
	t_data		*data;

	if (argc < 2)
		ft_exit(NULL, "You forgot to designate a map", NULL);
	if (argc > 2)
		ft_exit(NULL, "That is too many maps", NULL);
	map = ft_strjoin(s, argv[1]);
	fd = open (map, O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, "Error opening map", NULL);
	data = get_data();
	data->fd = fd;
	free (map);
	return (fd);
}