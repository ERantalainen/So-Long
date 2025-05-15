/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:06:14 by erantala          #+#    #+#             */
/*   Updated: 2025/05/13 15:06:51 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42.h"

typedef	struct s_character
{
	mlx_texture_t	char_up;
	mlx_texture_t	char_down;
	mlx_texture_t	char_left;
	mlx_texture_t	char_right;
	mlx_texture_t	basic;
}	t_char_text;

#endif