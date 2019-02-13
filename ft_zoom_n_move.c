/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:21:34 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/01 13:21:36 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		ft_zoom(t_struct *s, int mouse_x, int mouse_y)
{
	double mousere;
	double mouseim;
	double interpolation;

	mousere = ft_get_re(s, mouse_x);
	mouseim = ft_get_im(s, mouse_y);
	interpolation = 1.0 / s->mouse.zoom;
	s->mouse.re_min = interpolate(mousere, s->mouse.re_min, interpolation);
	s->mouse.im_min = interpolate(mouseim, s->mouse.im_min, interpolation);
	s->mouse.re_max = interpolate(mousere, s->mouse.re_max, interpolation);
	s->mouse.im_max = interpolate(mouseim, s->mouse.im_max, interpolation);
}

int			ft_move_mouse(int x, int y, t_struct *s)
{
	if ((x > 0 && x < WIDTH && y > 0 && y < HEIGHT && s->mouse.space == 1) &&
	(s->name == 2 || s->name == 7))
	{
		s->m.re = ft_get_re(s, x);
		s->m.im = ft_get_im(s, y);
	}
	if ((s->name == 2 || s->name == 7))
	{
		mlx_clear_window(s->mlx, s->win);
		ft_bzero(s->str, HEIGHT * WIDTH * 4);
		ft_create_thread(s);
		mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
		ft_infocolor(s);
	}
	return (0);
}
