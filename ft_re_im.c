/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_im.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:35:11 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/02 15:35:15 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_get_re(t_struct *s, double x)
{
	double	p_re;
	double	re;

	p_re = (s->mouse.re_max - s->mouse.re_min) / WIDTH;
	re = x * p_re + s->mouse.re_min;
	return (re);
}

double	ft_get_im(t_struct *s, double y)
{
	double	p_im;
	double	im;

	p_im = (s->mouse.im_max - s->mouse.im_min) / HEIGHT;
	im = y * p_im + s->mouse.im_min;
	return (im);
}
