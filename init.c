/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:10:58 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 18:57:45 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal_defaults(t_fractal *f)
{
	f->max_iter = 100;
	if (f->type == MANDELBROT)
	{
		f->min_re = -2.0;
		f->max_re = 2.0;
		f->min_im = -1.5;
		f->max_im = 1.5;
	}
	else if (f->type == JULIA)
	{
		f->min_re = -1.5;
		f->max_re = 1.5;
		f->min_im = -1.5;
		f->max_im = 1.5;
		if (f->julia_re == 0 && f->julia_im == 0)
		{
			f->julia_re = -0.7;
			f->julia_im = 0.27015;
		}
	}
}

static int	init_mlx(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "fractol");
	if (!app->win)
		return (0);
	app->img.img = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img.img)
		return (0);
	app->img.addr = mlx_get_data_addr(
			app->img.img,
			&app->img.bpp,
			&app->img.line_len,
			&app->img.endian);
	if (!app->img.addr)
		return (0);
	return (1);
}

int	init_app(t_app *app, int argc, char **argv)
{
	if (!parse_args(&app->fractal, argc, argv))
		return (0);
	init_fractal_defaults(&app->fractal);
	if (!init_mlx(app))
		return (0);
	mlx_key_hook(app->win, key_hook, app);
	mlx_mouse_hook(app->win, mouse_hook, app);
	mlx_hook(app->win, 17, 0, close_hook, app);
	return (1);
}
