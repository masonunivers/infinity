/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:23:18 by jomason           #+#    #+#             */
/*   Updated: 2026/05/05 12:47:19 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define WIDTH	800
# define HEIGHT	800

# define FRACTOL_A	1
# define FRACTOL_B	2
# define FRACTOL_C	3

# define K_ESC		65307
# define K_LEFT		65361
# define K_UP		65362
# define K_RIGHT	65363
# define K_DOWN		65364
# define M_UP		4
# define M_DOWN		5

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_view
{
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
}				t_view;

typedef struct s_coords
{
	double	c_real;
	double	c_imag;
	double	zr;
	double	zi;
}				t_coords;

typedef struct s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_view		view;
	t_coords	coords;
	int			max_iter;
	double		color_shift;
	int			dirty;
	int			type_id;
	void		(*draw_fractal)(struct s_fractol *f);
}				t_fractol;

t_fractol	*parse_args(int argc, char **argv);
void		cleanup_fractol(t_fractol *f);

void		draw_mandelbrot(t_fractol *f);
void		draw_julia(t_fractol *f);
void		draw_ship(t_fractol *f);
void		my_pixel_put(t_img *img, int x, int y, int color);
uint32_t	get_color(int iter, t_fractol *f);
int			redraw(t_fractol *f);

int			on_key_pass(int keycode, t_fractol *f);
int			on_mouse_hook(int button, int x, int y, void *param);
void		update_view(t_fractol *f, int keycode);
void		zoom_at_cursor(double factor, t_fractol *f, int x, int y);
void		reset_view(t_fractol *f);

double		atod(char *str);
int			check_valid_double(char *str);

#endif