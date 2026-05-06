/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:11:44 by jomason           #+#    #+#             */
/*   Updated: 2026/05/06 22:42:31 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup_fractol(t_fractol *f)
{
	if (!f)
		return ;
	if (f->img.img_ptr)
	{
		mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
		f->img.img_ptr = NULL;
	}
	if (f->win_ptr)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		f->win_ptr = NULL;
	}
	if (f->mlx_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
		f->mlx_ptr = NULL;
	}
	free(f);
}

int	exit_handler(t_fractol *f)
{
	cleanup_fractol(f);
	exit(EXIT_SUCCESS);
}

static void	init_fractol_settings(t_fractol *f)
{
	reset_view(f);
	f->max_iter = 100;
	f->color_shift = 0.0;
	f->dirty = 1;
	mlx_key_hook(f->win_ptr, on_key_pass, f);
	mlx_mouse_hook(f->win_ptr, on_mouse_hook, f);
	mlx_hook(f->win_ptr, 17, 0, exit_handler, f);
	mlx_loop_hook(f->mlx_ptr, redraw, f);
}

static void	run_fractol(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
	{
		free(f);
		exit(EXIT_FAILURE);
	}
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	if (!f->win_ptr)
	{
		free(f);
		exit(EXIT_FAILURE);
	}
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	init_fractol_settings(f);
	mlx_loop(f->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc < 2)
	{
		ft_putendl_fd("\n//ERROR MESSAGE // WRONG INPUT//\n", 2);
		ft_putendl_fd("Use: ./fractol <fractol_type>", 2);
		ft_putendl_fd("Available: Julia [Dec] [Dec], Mandel, Ship", 2);
		ft_putendl_fd("For example: ./fractol Julia 0.4 -0.3\n", 2);
		ft_putendl_fd("(Hint: Magic happens below 1.0 or above -1.0)", 2);
		ft_putendl_fd("\n//DON'T GIVE UP // TRY AGAIN//\n", 2);
		return (EXIT_FAILURE);
	}
	f = parse_args(argc, argv);
	if (!f)
		return (EXIT_FAILURE);
	run_fractol(f);
	return (EXIT_SUCCESS);
}
// simple: (enter together)
// ./fractol Julia -0.7 0.27
// ./fractol Julia -0.8 0.156
// ./fractol Julia 0.285 0.01
// complex:
// ./fractol Julia -0.4 0.6
// ./fractol Julia 0.285 0.0
// ./fractol Julia -0.835 -0.2321
