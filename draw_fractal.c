/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:50:07 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/02 18:50:09 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_choose_iter(t_struct *s, double re, double im)
{
	int i;

	if (s->name == 1)
		i = ft_mandelbrot(s->m, re, im);
	if (s->name == 2)
		i = ft_julia(s->m, re, im);
	if (s->name == 3)
		i = ft_burningship(s->m, re, im);
	if (s->name == 4)
		i = ft_tricorn(s->m, re, im);
	if (s->name == 5)
		i = ft_heart(s->m, re, im);
	if (s->name == 6)
		i = ft_celtic(s->m, re, im);
	if (s->name == 7)
		i = ft_grid(s->m, re, im);
	return (i);
}

void	ft_draw_color(t_struct *s, int x, int y, int iter)
{
	int		color;
	double	proc;

	proc = ft_procent(iter, 0, s->m.max_iter);
	color = ft_gradient(s->m.c1, s->m.c2, proc);
	if (s->m.psyho == 0)
	{
		if (iter == s->m.max_iter)
			ft_put_img(s, x, y, 0x0);
		else
			ft_put_img(s, x, y, color);
	}
	else
		ft_put_img(s, x, y, ft_psyho(s, iter));
}

void	*ft_draw_fractal(void *param)
{
	int			x;
	int			y;
	int			iter;
	t_thread	*t;

	t = (t_thread*)param;
	y = t->thread_id * (HEIGHT / THREADS);
	while (y < (t->thread_id + 1) * (HEIGHT / THREADS))
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = ft_choose_iter(t->s, ft_get_re(t->s, x), ft_get_im(t->s, y));
			ft_draw_color(t->s, x, y, iter);
			x++;
		}
		y++;
	}
	return (0);
}
