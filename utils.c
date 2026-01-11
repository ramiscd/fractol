/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:11:03 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 20:52:20 by rdamasce         ###   ########.fr       */
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
	if (!ft_strcmp(argv[1], "mandelbrot"))
		f->type = MANDELBROT;
	else if (!ft_strcmp(argv[1], "julia"))
	{
		f->type = JULIA;
		if (argc >= 4)
		{
			f->julia_re = ft_atof(argv[2]);
			f->julia_im = ft_atof(argv[3]);
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static double	parse_fraction(const char *str, int *i)
{
	double	frac;
	double	div;

	frac = 0.0;
	div = 10.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		frac += (str[*i] - '0') / div;
		div *= 10.0;
		(*i)++;
	}
	return (frac);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		i;

	result = 0.0;
	sign = 1.0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		result += parse_fraction(str, &i);
	}
	return (result * sign);
}
