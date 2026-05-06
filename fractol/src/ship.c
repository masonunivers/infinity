/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:11:57 by jomason           #+#    #+#             */
/*   Updated: 2026/04/25 10:20:23 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_ship_coords(t_fractol *f, int x, int y)
{
	f->coords.c_real = f->view.min_real + (double)x * (f->view.max_real
			- f->view.min_real) / WIDTH;
	f->coords.c_imag = f->view.max_imag - (double)y * (f->view.max_imag
			- f->view.min_imag) / HEIGHT;
	f->coords.zr = 0.0;
	f->coords.zi = 0.0;
}

static int	iterate_ship(t_fractol *f)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < f->max_iter && (f->coords.zr * f->coords.zr + f->coords.zi
			* f->coords.zi) < 4.0)
	{
		tmp = f->coords.zr * f->coords.zr - f->coords.zi * f->coords.zi
			+ f->coords.c_real;
		f->coords.zi = -2.0 * fabs(f->coords.zr * f->coords.zi)
			+ f->coords.c_imag;
		f->coords.zr = fabs(tmp);
		iter++;
	}
	return (iter);
}

void	draw_ship(t_fractol *f)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			init_ship_coords(f, x, y);
			iter = iterate_ship(f);
			my_pixel_put(&(f->img), x, y, get_color(iter, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
