/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:11:55 by jomason           #+#    #+#             */
/*   Updated: 2026/04/30 23:45:05 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_putendl_fd("Error: Invalid fractal name or parameters.", 2);
	ft_putendl_fd("Use: ./fractol <fractal>", 2);
	ft_putendl_fd("Fractals: Julia [Dec] [Dec], Mandel, Ship", 2);
}

static int	parse_julia(t_fractol *f, int argc, char **argv)
{
	f->draw_fractal = draw_julia;
	f->type_id = FRACTOL_A;
	if (argc == 2)
	{
		f->coords.c_real = -0.75;
		f->coords.c_imag = 0.11;
	}
	else if (argc == 4)
	{
		if (!check_valid_double(argv[2]) || !check_valid_double(argv[3]))
			return (0);
		f->coords.c_real = atod(argv[2]);
		f->coords.c_imag = atod(argv[3]);
	}
	else
		return (0);
	return (1);
}
//parameter handling. julia's special

static int	parse_fractal(t_fractol *f, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "Julia", 6))
		return (parse_julia(f, argc, argv));
	else if (!ft_strncmp(argv[1], "Mandel", 7) && argc == 2)
	{
		f->draw_fractal = draw_mandelbrot;
		f->type_id = FRACTOL_B;
		return (1);
	}
	else if (!ft_strncmp(argv[1], "Ship", 5) && argc == 2)
	{
		f->draw_fractal = draw_ship;
		f->type_id = FRACTOL_C;
		return (1);
	}
	return (0);
}

static t_fractol	*init_fractol_struct(void)
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	if (!f)
	{
		ft_putendl_fd("Error: Malloc failed, you fool!", 2);
		return (NULL);
	}
	f->mlx_ptr = NULL;
	f->win_ptr = NULL;
	f->img.img_ptr = NULL;
	f->draw_fractal = NULL;
	f->type_id = 0;
	f->max_iter = 256;
	f->dirty = 1;
	f->color_shift = 0.0;
	return (f);
}

t_fractol	*parse_args(int argc, char **argv)
{
	t_fractol	*f;

	f = init_fractol_struct();
	if (!f)
		return (NULL);
	if (!parse_fractal(f, argc, argv))
	{
		print_usage();
		free(f);
		return (NULL);
	}
	return (f);
}
