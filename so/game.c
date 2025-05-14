/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:35:29 by erantala          #+#    #+#             */
/*   Updated: 2025/05/14 16:41:45 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"


int	ft_game_loop(mlx_t *mlx, t_images *img, char **map)
{
	mlx_close_hook(mlx, ft_close(mlx, NULL), NULL);
	mlx_loop(mlx);
	ft_frearr((void **)map, ft_stralen(map));
	ft_exit(mlx, "", NULL);
	return (0);
}
