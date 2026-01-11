/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdamasce <rdamasce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:35:19 by rdamasce          #+#    #+#             */
/*   Updated: 2026/01/11 14:35:20 by rdamasce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_app	app;

	if (!init_app(&app, argc, argv))
		return (1);
	render(&app);
	mlx_loop(app.mlx);
	return (0);
}
