/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:06:14 by erantala          #+#    #+#             */
/*   Updated: 2025/05/20 18:33:51 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42.h"

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
	mlx_texture_t *char_up;
	mlx_texture_t *char_left;
	mlx_texture_t *char_right;
	mlx_texture_t *basic;
	mlx_texture_t *wall;
	mlx_texture_t *coll;
	mlx_texture_t *exit;
	mlx_texture_t *ground;
	mlx_texture_t **nbr;
}	t_txt;

typedef	struct	s_images
{
	mlx_image_t	*wall_i;
	mlx_image_t	*exit_i;
	mlx_image_t	*ground_i;
	mlx_image_t	*text;
	mlx_image_t	*char_i;
	mlx_image_t	*char_u;
	mlx_image_t	*char_l;
	mlx_image_t	*char_r;
	mlx_image_t	**coll_i;
	mlx_image_t **nbr_i;
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
	t_point		char_cord;
}	t_data;

int				ft_valid_input(int argc, char **argv);
int				check_chars(char *map_line);
char			**get_map(int fd, t_point *path);
int				check_edges(char *line);
t_point			flood_fill(char **map, t_point size, int row, int col);
int				check_map_valid(char **map);
int				check_path(char **map, int spawn, t_point *size, char *map_line);
int				check_fill_char(char c);
void			ft_step_print(mlx_t *mlx, int stp);
void			ft_exit(mlx_t *mlx, const char *s, void *fre);
int				ft_game_loop(char **map, mlx_t *mlx);
int 			ft_count_char(char *s, char c);

void			create_map(int line_len, int line_count);
void			ft_init_textures(size_t map_size, char **map, mlx_t *mlx);
void			ft_init_images( size_t map_size, char **map, t_txt *textures, mlx_t *mlx);
void			ft_display_images(size_t map_size, char **map, t_images *images, mlx_t *mlx);
void			ft_background(mlx_t *mlx, size_t map_size, t_images *images);
void			ft_display_img(mlx_t *mlx);
void			ft_walls(mlx_t *mlx, t_images *img);
void			ft_center(mlx_t *mlx, char **map, char target, mlx_image_t *img);
void			ft_collectibles(mlx_t *mlx, char **map, t_images *img);

void			key_hook(void *param);
void			ft_close(void *param);

t_images		*ft_init_struct(t_images *img);
t_data			*get_data();
t_images		*get_images();
t_data			*ft_init_data();
void			ft_init_char_txt(mlx_t *mlx, t_txt *txt);
void			ft_init_char_img(mlx_t *mlx, t_txt *txt, t_images *img);
void			ft_init_nbr_img(mlx_t *mlx, t_txt *txt, t_images *img);
void			ft_init_nbr_txt(mlx_t *mlx, t_txt *txt);
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