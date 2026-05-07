/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:54 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:37:00 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_trivially_rejected(t_point_render start, t_point_render end)
{
	return ((start.x < 0 && end.x < 0) || (start.x >= 1000 && end.x >= 1000)
		|| (start.y < 0 && end.y < 0) || (start.y >= 1000 && end.y >= 1000));
}
//if entire segment out of bounds, skip drawing it

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	put_pixel_if_inside(mlx_image_t *img, int x, int y)
{
	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
		mlx_put_pixel(img, x, y, 0xFFFFFFFF);
}

void	on_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	cleanup_fdf(data);
	exit(0);
}
