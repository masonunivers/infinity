/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:06 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:47 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	init_map(t_map *map, char *filename, t_camerainfo *cam)
{
	if (!compute_map_dimensions(&map->width, &map->height, filename))
		return (false);
	if (!parse_map_points(map, filename))
		return (false);
	if (!compute_render_points(map, cam))
	{
		free_points_in(map);
		free_points_render(map);
		return (false);
	}
	return (true);
}

static bool	init_mlx(t_data *data)
{
	data->mlx = mlx_init(1000, 1000, "fdf", false);
	if (!data->mlx)
		return (false);
	return (true);
}

static void	init_camera(t_camerainfo *camera)
{
	camera->zoom = 10;
	camera->offset_x = 500;
	camera->offset_y = 500;
}

bool	init_image(mlx_image_t **img, mlx_t *mlx)
{
	*img = mlx_new_image(mlx, 1000, 1000);
	if (!*img)
		return (false);
	if (mlx_image_to_window(mlx, *img, 0, 0) < 0)
	{
		mlx_delete_image(mlx, *img);
		*img = NULL;
		return (false);
	}
	return (true);
}

bool	init_fdf(t_data *data, char *filename)
{
	data->map = calloc(1, sizeof(t_map));
	if (!data->map)
		return (ft_putstr_fd("Memory allocation failed\n", 2), false);
	init_camera(&data->camera);
	if (!init_mlx(data))
		return (free(data->map), false);
	if (!init_map(data->map, filename, &data->camera))
		return (free(data->map), mlx_terminate(data->mlx),
			ft_putstr_fd("Error initializing map\n", 2), false);
	if (!init_image(&data->img, data->mlx))
		return (cleanup_fdf(data), false);
	render_map(data);
	return (true);
}
