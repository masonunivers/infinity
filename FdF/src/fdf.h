/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:28:45 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:45 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point_in
{
	int				x;
	int				y;
	int				z;
}					t_point_in;

typedef struct s_point_render
{
	int				x;
	int				y;
}					t_point_render;

typedef struct s_map
{
	int				width;
	int				height;
	t_point_in		**points_in;
	t_point_render	**points_render;
}					t_map;

typedef struct s_camerainfo
{
	double			zoom;
	int				offset_x;
	int				offset_y;
}					t_camerainfo;

typedef struct s_data
{
	mlx_t			*mlx;
	t_map			*map;
	t_camerainfo	camera;
	mlx_image_t		*img;
}					t_data;

bool	alloc_input_map(t_map *map, int width, int height);
bool	alloc_render_points(t_map *map, int width, int height);

bool	parse_map_points(t_map *map, char *filename);
bool	compute_map_dimensions(int *width, int *height, char *filename);

void	free_points_in(t_map *map);
void	free_points_render(t_map *map);
void	cleanup_fdf(t_data *data);

bool	init_fdf(t_data *data, char *filename);
bool	init_image(mlx_image_t **img, mlx_t *mlx);

int		main(int ac, char **av);

bool	compute_render_points(t_map *map, t_camerainfo *cam);

void	on_key_press(mlx_key_data_t keydata, void *param);

void	render_map(t_data *data);

void	on_close(void *param);
void	put_pixel_if_inside(mlx_image_t *img, int x, int y);
int		ft_abs(int value);
bool	is_trivially_rejected(t_point_render start, t_point_render end);

#endif