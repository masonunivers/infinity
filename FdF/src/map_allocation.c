/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:22:12 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:51 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	alloc_render_points(t_map *map, int width, int height)
{
	int	y;

	map->points_render = malloc(sizeof(t_point_render *) * height);
	if (!map->points_render)
		return (false);
	y = 0;
	while (y < height)
	{
		map->points_render[y] = malloc(sizeof(t_point_render) * width);
		if (!map->points_render[y])
		{
			while (--y >= 0)
				free(map->points_render[y]);
			free(map->points_render);
			map->points_render = NULL;
			return (false);
		}
		y++;
	}
	return (true);
}

bool	alloc_input_map(t_map *map, int width, int height)
{
	int	y;

	map->points_in = malloc(sizeof(t_point_in *) * height);
	if (!map->points_in)
		return (false);
	y = 0;
	while (y < height)
	{
		map->points_in[y] = malloc(sizeof(t_point_in) * width);
		if (!map->points_in[y])
		{
			while (--y >= 0)
				free(map->points_in[y]);
			free(map->points_in);
			map->points_in = NULL;
			return (false);
		}
		y++;
	}
	return (true);
}
