/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:11:50 by jomason           #+#    #+#             */
/*   Updated: 2026/04/25 10:15:26 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key_pass(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		cleanup_fractol(f);
	else if (keycode == 65362 || keycode == 65364 || keycode == 65361
		|| keycode == 65363)
	{
		update_view(f, keycode);
	}
	else if (keycode == 32)
	{
		f->color_shift += 0.1;
		if (f->color_shift >= 1.0)
			f->color_shift = 0.0;
		f->dirty = 1;
	}
	return (0);
}

int	on_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;
	double		factor;

	f = (t_fractol *)param;
	if (button == 4)
		factor = 0.9;
	else if (button == 5)
		factor = 1.1;
	else
		return (0);
	zoom_at_cursor(factor, f, x, y);
	f->dirty = 1;
	return (0);
}

void	zoom_at_cursor(double factor, t_fractol *f, int x, int y)
{
	double	c_real;
	double	c_imag;

	c_real = f->view.min_real + (f->view.max_real - f->view.min_real)
		* (double)x / (double)WIDTH;
	c_imag = f->view.max_imag - (f->view.max_imag - f->view.min_imag)
		* (double)y / (double)HEIGHT;
	f->view.min_real = c_real - (c_real - f->view.min_real) * factor;
	f->view.max_real = c_real + (f->view.max_real - c_real) * factor;
	f->view.min_imag = c_imag - (c_imag - f->view.min_imag) * factor;
	f->view.max_imag = c_imag + (f->view.max_imag - c_imag) * factor;
}
// double	real_range;
// double	imag_range;
// real_range = f->view.max_real - f->view.min_real;
// imag_range = f->view.max_imag - f->view.min_imag;
// if (real_range < 1e-12 || imag_range < 1e-12)
// 	return ;
// reset_view(f);
