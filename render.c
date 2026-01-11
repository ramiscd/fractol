/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:23:08 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 19:00:56 by rdamasce         ###   ########.fr       */
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

void	render(t_app *app)
{
	int		x;
	int		y;
	int		iter;
	double	cr;
	double	ci;
	double	re_factor;
	double	im_factor;

	y = 0;
	re_factor = (app->fractal.max_re - app->fractal.min_re) / WIDTH;
	im_factor = (app->fractal.max_im - app->fractal.min_im) / HEIGHT;
	while (y < HEIGHT)
	{
		ci = app->fractal.max_im - y * im_factor;
		x = 0;
		while (x < WIDTH)
		{
			cr = app->fractal.min_re + x * re_factor;
			if (app->fractal.type == MANDELBROT)
				iter = mandelbrot(cr, ci, app->fractal.max_iter);
			else
				iter = julia(cr, ci, &app->fractal);
			put_pixel(&app->img, x, y, get_color(iter, app->fractal.max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
}
