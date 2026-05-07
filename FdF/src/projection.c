/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:23 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:56 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	project_to_2d(t_map *map, int x, int y, t_camerainfo *cam)
{
	double	angle;
	double	iso_x;
	double	iso_y;
	double	scaled_x;
	double	scaled_y;

	angle = M_PI / 6;
	iso_x = (x - y) * cos(angle);
	iso_y = (x + y) * sin(angle) - map->points_in[y][x].z;
	scaled_x = iso_x * cam->zoom + cam->offset_x;
	scaled_y = iso_y * cam->zoom + cam->offset_y;
	map->points_render[y][x].x = round(scaled_x);
	map->points_render[y][x].y = round(scaled_y);
}

bool	compute_render_points(t_map *map, t_camerainfo *cam)
{
	int	y;
	int	x;

	if (!alloc_render_points(map, map->width, map->height))
		return (false);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			project_to_2d(map, x, y, cam);
			x++;
		}
		y++;
	}
	return (true);
}
