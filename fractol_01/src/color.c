/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:11:48 by jomason           #+#    #+#             */
/*   Updated: 2026/05/04 18:20:58 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	rgba(unsigned char r, unsigned char g, unsigned char b,
		unsigned char a)
{
	uint32_t	res;

	res = 0;
	res |= (uint32_t)a << 24;
	res |= (uint32_t)r << 16;
	res |= (uint32_t)g << 8;
	res |= (uint32_t)b;
	return (res);
}

uint32_t	get_color(int iter, t_fractol *f)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter >= f->max_iter)
		return (rgba(0, 0, 0, 0));
	t = fmod((double)iter / f->max_iter + f->color_shift, 1.0);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (rgba(r, g, b, 0));
}
