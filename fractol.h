/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:35:25 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 20:52:06 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MANDELBROT 1
# define JULIA 2

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		max_iter;
	double	julia_re;
	double	julia_im;
	int		type;
}	t_fractal;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_fractal	fractal;
}	t_app;

int				init_app(t_app *app, int argc, char **argv);
void			render(t_app *app);
int				mandelbrot(double cr, double ci, int max_iter);
int				julia(double zr, double zi, t_fractal *f);
int				key_hook(int keycode, t_app *app);
int				mouse_hook(int button, int x, int y, t_app *app);
int				close_hook(t_app *app);
int				parse_args(t_fractal *f, int argc, char **argv);
void			put_pixel(t_img *img, int x, int y, int color);
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atof(const char *str);

#endif
