/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:11:03 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 18:53:26 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	parse_args(t_fractal *f, int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!strcmp(argv[1], "mandelbrot"))
		f->type = MANDELBROT;
	else if (!strcmp(argv[1], "julia"))
	{
		f->type = JULIA;
		if (argc >= 4)
		{
			f->julia_re = atof(argv[2]);
			f->julia_im = atof(argv[3]);
		}
		else
		{
			f->julia_re = -0.7;
			f->julia_im = 0.27015;
		}
	}
	else
		return (0);
	return (1);
}
