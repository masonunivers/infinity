/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:12:01 by jomason           #+#    #+#             */
/*   Updated: 2026/05/06 16:36:10 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	redraw(t_fractol *f)
{
	if (f->dirty)
	{
		f->draw_fractal(f);
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
		f->dirty = 0;
	}
	return (0);
}

static void	calculate_imag_bounds(t_fractol *f)
{
	double	real_range;
	double	image_range;
	double	aspect_ratio;

	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	real_range = f->view.max_real - f->view.min_real;
	image_range = real_range / aspect_ratio;
	if (f->type_id == FRACTOL_C)
	{
		f->view.max_imag = 0.0;
		f->view.min_imag = -image_range;
	}
	else
	{
		f->view.max_imag = image_range / 2.0;
		f->view.min_imag = -image_range / 2.0;
	}
}

static void	set_real_bounds(t_fractol *f)
{
	if (f->type_id == FRACTOL_B)
	{
		f->view.min_real = -2.0;
		f->view.max_real = 1.0;
	}
	else if (f->type_id == FRACTOL_A)
	{
		f->view.min_real = -2.0;
		f->view.max_real = 2.0;
	}
	else if (f->type_id == FRACTOL_C)
	{
		f->view.min_real = -2.0;
		f->view.max_real = 2.0;
	}
}
// sets bounds where the fractal actually lives
// more than 2, renders extra emptiness

void	reset_view(t_fractol *f)
{
	set_real_bounds(f);
	calculate_imag_bounds(f);
	f->dirty = 1;
}
