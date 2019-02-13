/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:54 by lpohribn          #+#    #+#             */
/*   Updated: 2018/02/28 17:48:56 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_info_mandelbrot(t_fractal *m, t_mouse *mouse)
{
	mouse->re_min = -2.0;
	mouse->re_max = 0.5;
	mouse->im_min = -1.25;
	mouse->im_max = 1.25;
	mouse->zoom = 1.0;
	m->max_iter = 50;
	m->c1 = 0x0;
	m->c2 = 0xFF0000;
	m->psyho = 0;
}

void	ft_info_julia(t_fractal *m, t_mouse *mouse)
{
	mouse->re_min = -2.0;
	mouse->re_max = 2.0;
	mouse->im_min = -2.0;
	mouse->im_max = 2.0;
	mouse->space = 1;
	mouse->zoom = 1.0;
	m->max_iter = 50;
	m->c1 = 0x0;
	m->c2 = 0xFF0000;
	m->psyho = 0;
}

void	ft_info(t_struct *s)
{
	if (s->name == 1)
		ft_info_mandelbrot(&s->m, &s->mouse);
	else
		ft_info_julia(&s->m, &s->mouse);
}

void	ft_infocolor(t_struct *s)
{
	char *str;

	str = ft_itoa(s->m.red);
	mlx_string_put(s->mlx, s->win, 0, 0, 0xFFFFFF, "RED:");
	mlx_string_put(s->mlx, s->win, 40, 0, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(s->m.green);
	mlx_string_put(s->mlx, s->win, 0, 20, 0xFFFFFF, "GREEN:");
	mlx_string_put(s->mlx, s->win, 60, 20, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(s->m.blue);
	mlx_string_put(s->mlx, s->win, 0, 40, 0xFFFFFF, "BLUE:");
	mlx_string_put(s->mlx, s->win, 50, 40, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(s->m.max_iter);
	mlx_string_put(s->mlx, s->win, 0, 60, 0xFFFFFF, "ITERATION:");
	mlx_string_put(s->mlx, s->win, 100, 60, 0xFFFFFF, str);
	free(str);
}
