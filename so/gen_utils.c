/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:57:27 by erantala          #+#    #+#             */
/*   Updated: 2025/05/14 16:09:18 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <string.h>

void	ft_exit(mlx_t *mlx, const char *s, void *fre)
{
	if (mlx && (!s[0]))
	{
		mlx_terminate(mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx != NULL)
	{
		ft_printf("Error\n%s", s);
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Error\n%s", s);
		exit(EXIT_FAILURE);
	}
}

mlx_closefunc	ft_close()
{
	return (NULL);
}

