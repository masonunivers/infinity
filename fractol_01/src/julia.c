/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:50:14 by jomason           #+#    #+#             */
/*   Updated: 2026/05/05 11:06:49 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_julia(t_fractol *f)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < f->max_iter && (f->coords.zr * f->coords.zr + f->coords.zi
			* f->coords.zi) < 4.0)
	{
		tmp = f->coords.zr * f->coords.zr - f->coords.zi * f->coords.zi
			+ f->coords.c_real;
		f->coords.zi = 2.0 * f->coords.zr * f->coords.zi + f->coords.c_imag;
		f->coords.zr = tmp;
		iter++;
	}
	return (iter);
}
// // This is the (r^2 - i^2) + cr part
// tmp = f->coords.zr * f->coords.zr - f->coords.zi
// 	* f->coords.zi + f->coords.c_real;
// // This is the (2ri) + ci part
// f->coords.zi = 2.0 * f->coords.zr * f->coords.zi + f->coords.c_imag;
// // This updates the real part using the temp variable
// f->coords.zr = tmp;

static void	init_julia_coords(t_fractol *f, int x, int y)
{
	f->coords.zr = f->view.min_real + (f->view.max_real - f->view.min_real)
		* (double)x / (double)WIDTH;
	f->coords.zi = f->view.max_imag - (f->view.max_imag - f->view.min_imag)
		* (double)y / (double)HEIGHT;
}

void	draw_julia(t_fractol *f)
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
			init_julia_coords(f, x, y);
			iter = iterate_julia(f);
			my_pixel_put(&(f->img), x, y, get_color(iter, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
