/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:22:49 by erantala          #+#    #+#             */
/*   Updated: 2025/05/19 19:28:15 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <math.h>
# include "MLX42.h"

# define MAX_WIDTH 3840
# define MAX_HEIGHT 2160

typedef struct	s_point
{
	int	x;
	int y;
}	t_point;

typedef	struct	s_textures
{
	mlx_texture_t *character;
	mlx_texture_t *wall;
	mlx_texture_t *coll;
	mlx_texture_t *exit;
	mlx_texture_t *ground;
}	t_txt;

typedef	struct	s_images
{
	mlx_image_t	*char_i;
	mlx_image_t	*wall_i;
	mlx_image_t	**coll_i;
	mlx_image_t	*exit_i;
	mlx_image_t	*ground_i;
}	t_images;

typedef	struct s_data
{
	char		**map;
	t_images	*img;
	int			coll;
	int			coll_c;
	int			steps;
	int			fd;
	mlx_t		*mlx;
}	t_data;

int				ft_valid_input(int argc, char **argv);
int				check_chars(char *map_line);
char			**get_map(int fd, t_point *path);
int				check_edges(char *line);
t_point			flood_fill(char **map, t_point size, int row, int col);
int				check_map_valid(char **map);
int				check_path(char **map, int spawn, t_point *size, char *map_line);
int				check_fill_char(char c);

void			ft_exit(mlx_t *mlx, const char *s, void *fre);
int				ft_game_loop(char **map, mlx_t *mlx);
int 			ft_count_char(char *s, char c);
void			create_map(int line_len, int line_count);
void			ft_init_textures(size_t map_size, char **map, mlx_t *mlx);
void			ft_init_images( size_t map_size, char **map, t_txt *textures, mlx_t *mlx);
void			ft_display_images(size_t map_size, char **map, t_images *images, mlx_t *mlx);
void			ft_background(mlx_t *mlx, size_t map_size, t_images *images);
void			ft_walls(mlx_t *mlx, t_images *img);
void			ft_center(mlx_t *mlx, char **map, char target, mlx_image_t *img);
void			ft_collectibles(mlx_t *mlx, char **map, t_images *img);
void			key_hook(void *param);
void			ft_close(void *param);

t_images		*ft_init_struct(t_images *img);
t_data			*get_data();
t_images		*get_images();
t_data			*ft_init_data();
void			free_data();

void			ft_move_up(mlx_t *mlx);
void			ft_move_down(mlx_t *mlx);
void			ft_move_right(mlx_t *mlx);
void			ft_move_left(mlx_t *mlx);
void			ft_free_struct(mlx_image_t **data, int row);
int				ft_get_cords(mlx_t *mlx, char **map, int x, int y);
void			ft_init_coll(t_txt *txt, mlx_t *mlx);

void			ft_is_exit(mlx_t *mlx);
#endif