/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:42 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:48 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	handle_camera_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_UP)
		data->camera.offset_y -= 10;
	else if (keydata.key == MLX_KEY_DOWN)
		data->camera.offset_y += 10;
	else if (keydata.key == MLX_KEY_LEFT)
		data->camera.offset_x -= 10;
	else if (keydata.key == MLX_KEY_RIGHT)
		data->camera.offset_x += 10;
	else if (keydata.key == MLX_KEY_EQUAL && data->camera.zoom < 50)
		data->camera.zoom *= 1.1;
	else if (keydata.key == MLX_KEY_MINUS && data->camera.zoom > 0.1)
		data->camera.zoom *= 0.9;
	else
		return (false);
	return (true);
}

static bool	refresh_image(t_data *data)
{
	free_points_render(data->map);
	if (!compute_render_points(data->map, &data->camera))
		return (false);
	mlx_delete_image(data->mlx, data->img);
	data->img = NULL;
	if (!init_image(&data->img, data->mlx))
		return (false);
	render_map(data);
	return (true);
}

void	on_key_press(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		return ;
	}
	if (!handle_camera_key(keydata, data))
		return ;
	if (!refresh_image(data))
		mlx_close_window(data->mlx);
}
