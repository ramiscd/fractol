/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:36:08 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 19:49:49 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ZOOM_IN 4
#define ZOOM_OUT 5
#define PAN_STEP 0.1

static void	pan_fractal(t_fractal *f, int keycode)
{
	double	dx;
	double	dy;

	dx = (f->max_re - f->min_re) * PAN_STEP;
	dy = (f->max_im - f->min_im) * PAN_STEP;
	if (keycode == 65361)
	{
		f->min_re -= dx;
		f->max_re -= dx;
	}
	else if (keycode == 65363)
	{
		f->min_re += dx;
		f->max_re += dx;
	}
	else if (keycode == 65362)
	{
		f->min_im += dy;
		f->max_im += dy;
	}
	else if (keycode == 65364)
	{
		f->min_im -= dy;
		f->max_im -= dy;
	}
}

int	key_hook(int keycode, t_app *app)
{
	if (keycode == 65307)
		exit(0);
	pan_fractal(&app->fractal, keycode);
	render(app);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_app *app)
{
	double	zoom_factor;
	double	cr;
	double	ci;
	double	re_width;
	double	im_height;

	re_width = app->fractal.max_re - app->fractal.min_re;
	im_height = app->fractal.max_im - app->fractal.min_im;
	cr = app->fractal.min_re + x * re_width / WIDTH;
	ci = app->fractal.max_im - y * im_height / HEIGHT;
	if (button == ZOOM_IN)
		zoom_factor = 0.8;
	else if (button == ZOOM_OUT)
		zoom_factor = 1.25;
	else
		return (0);
	app->fractal.min_re = cr + (app->fractal.min_re - cr) * zoom_factor;
	app->fractal.max_re = cr + (app->fractal.max_re - cr) * zoom_factor;
	app->fractal.min_im = ci + (app->fractal.min_im - ci) * zoom_factor;
	app->fractal.max_im = ci + (app->fractal.max_im - ci) * zoom_factor;
	render(app);
	return (0);
}

int	close_hook(t_app *app)
{
	(void)app;
	exit(0);
	return (0);
}
