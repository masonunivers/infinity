/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:11:59 by jomason           #+#    #+#             */
/*   Updated: 2026/04/20 21:14:47 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_view(t_fractol *f, double move_real, double move_imag)
{
	double	h_range;
	double	v_range;

	h_range = f->view.max_real - f->view.min_real;
	v_range = f->view.max_imag - f->view.min_imag;
	f->view.min_real += move_real * h_range;
	f->view.max_real += move_real * h_range;
	f->view.min_imag += move_imag * v_range;
	f->view.max_imag += move_imag * v_range;
}

void	update_view(t_fractol *f, int keycode)
{
	if (keycode == 65362)
		move_view(f, 0, 0.05);
	else if (keycode == 65364)
		move_view(f, 0, -0.05);
	else if (keycode == 65361)
		move_view(f, -0.05, 0);
	else if (keycode == 65363)
		move_view(f, 0.05, 0);
	f->dirty = 1;
}
