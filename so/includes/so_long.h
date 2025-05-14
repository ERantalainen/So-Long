/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:22:49 by erantala          #+#    #+#             */
/*   Updated: 2025/05/14 16:51:32 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_point
{
	int	x;
	int y;
}	t_point;

# include <string.h>
# include <stdio.h>
# include <math.h>
# include "MLX42.h"

# define MAX_WIDTH 3840
# define MAX_HEIGHT 2160

typedef	struct	s_textures
{
	mlx_texture_t *character;
	mlx_texture_t *wall;
	mlx_texture_t *collectible;
	mlx_texture_t *exit;
	mlx_texture_t *ground;
}	t_txt;

typedef	struct	s_images
{
	mlx_image_t	*char_i;
	mlx_image_t	*wall_i;
	mlx_image_t	*coll_i;
	mlx_image_t	*exit_i;
	mlx_image_t	*ground_i;
}	t_images;

int				check_chars(char *map_line);
char			**get_map(int fd, t_point *path);
int				check_edges(char *line);
t_point			flood_fill(char **map, t_point size, int row, int col);
int				check_map_valid(char **map);
int				check_path(char **map, int spawn, t_point *size, char *map_line);
int				check_fill_char(char c);
void			ft_exit(mlx_t *mlx, const char *s, void *fre);
int				ft_game_loop(mlx_t *mlx, t_images *img, char **map);
size_t 			ft_count_char(char *s, char c);
void	create_map(char **map, int line_len, int line_count, mlx_t *mlx);
void	ft_init_textures(mlx_t *mlx, size_t map_size, char **map);
void	ft_init_images(mlx_t *mlx, size_t map_size, char **map, t_txt *textures);
void	ft_display_images(mlx_t *mlx, size_t map_size, char **map, t_images *images);
void	ft_background(mlx_t *mlx, char **map, size_t map_size, t_images *images);
void	ft_walls(mlx_t *mlx, char **map, size_t map_size, t_images *img);
void	ft_center(mlx_t *mlx, char **map, char target, mlx_image_t *img);
mlx_closefunc	ft_close();

#endif