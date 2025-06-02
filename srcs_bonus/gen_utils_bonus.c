/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:57:27 by erantala          #+#    #+#             */
/*   Updated: 2025/06/02 13:59:45 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"
#include <fcntl.h>

void	ft_exit(mlx_t *mlx, const char *s, void *fre)
{
	free_data();
	if (mlx != NULL)
		mlx_terminate(mlx);
	if (ft_strncmp(s, "You lost", 8) == 0)
	{
		ft_putendl_fd("You lost, you've gone over the maximum step count", 1);
		exit(EXIT_SUCCESS);
	}
	if (!s[0])
		exit(EXIT_SUCCESS);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd((char *)s, 2);
		free(fre);
	}
	exit(EXIT_FAILURE);
}

void	ft_close(void *param)
{
	if (!param)
		ft_exit(NULL, "", NULL);
	else
		ft_exit(param, "", NULL);
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
