/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:17 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 19:02:29 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	int		iter;
	double	tmp;

	zr = 0.0;
	zi = 0.0;
	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

int	julia(double zr, double zi, t_fractal *f)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < f->max_iter)
	{
		tmp = zr * zr - zi * zi + f->julia_re;
		zi = 2 * zr * zi + f->julia_im;
		zr = tmp;
		iter++;
	}
	return (iter);
}
