/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:22:57 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:55 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points_render(t_map *map)
{
	int	y;

	if (!map->points_render)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->points_render[y]);
		y++;
	}
	free(map->points_render);
	map->points_render = NULL;
}

void	free_points_in(t_map *map)
{
	int	y;

	if (!map->points_in)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->points_in[y]);
		y++;
	}
	free(map->points_in);
	map->points_in = NULL;
}

void	cleanup_fdf(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
	{
		free_points_in(data->map);
		free_points_render(data->map);
		free(data->map);
	}
	if (data->img && data->mlx)
		mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
		mlx_terminate(data->mlx);
}
