/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:57:27 by erantala          #+#    #+#             */
/*   Updated: 2025/05/16 15:01:40 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <string.h>

void	ft_exit(mlx_t *mlx, const char *s, void *fre)
{
	int		res;

	if (mlx && (!s[0]))
	{
		mlx_terminate(mlx);
		res = EXIT_SUCCESS;
	}
	else if (mlx != NULL)
	{
		ft_printf("Error\n%s", s);
		mlx_terminate(mlx);
		res = EXIT_FAILURE;
	}
	else
	{
		ft_printf("Error\n%s", s);
		free (fre);
		res = EXIT_FAILURE;
	}

	exit(res);
}

mlx_closefunc	ft_close()
{
	return (NULL);
}

t_data	*get_data()
{
	static t_data	*data;
	if (data == NULL)
		data = ft_init_data();
	return (data);
}

t_data	*ft_init_data()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = NULL;
	data->map = malloc(sizeof(char **));
	if (!data->map)
		return (0);
	data->map = NULL;
	data->coll = 0;
	return (data);
}

void	free_data()
{
	t_data	*data;

	data = get_data();
	ft_frearr((void **)data->map, ft_stralen(data->map));
	free(data->img);
	free(data->map);
	free(data);
}