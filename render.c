/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:23:08 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 20:01:41 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == max_iter)
		return (0x000000);
	r = (iter * 9) % 256;
	g = (iter * 7) % 256;
	b = (iter * 5) % 256;
	return ((r << 16) | (g << 8) | b);
}

static void	draw_pixel(t_app *app, int x, int y)
{
	double	cr;
	double	ci;
	double	re_factor;
	double	im_factor;
	int		iter;

	re_factor = (app->fractal.max_re - app->fractal.min_re) / WIDTH;
	im_factor = (app->fractal.max_im - app->fractal.min_im) / HEIGHT;
	ci = app->fractal.max_im - y * im_factor;
	cr = app->fractal.min_re + x * re_factor;
	if (app->fractal.type == MANDELBROT)
		iter = mandelbrot(cr, ci, app->fractal.max_iter);
	else
		iter = julia(cr, ci, &app->fractal);
	put_pixel(&app->img, x, y,
		get_color(iter, app->fractal.max_iter));
}

void	render(t_app *app)
{
	int		x;
	int		y;
	double	re_factor;
	double	im_factor;

	re_factor = (app->fractal.max_re - app->fractal.min_re) / WIDTH;
	im_factor = (app->fractal.max_im - app->fractal.min_im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(app, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
}
