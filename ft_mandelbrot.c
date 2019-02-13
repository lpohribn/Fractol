/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:49:21 by lpohribn          #+#    #+#             */
/*   Updated: 2018/02/26 19:49:24 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_fractal m, double re, double im)
{
	int i;

	i = 0;
	m.a = re;
	m.b = im;
	while (i < m.max_iter)
	{
		m.aa = m.a * m.a;
		m.bb = m.b * m.b;
		m.twoab = 2.0 * m.a * m.b;
		m.a = m.aa - m.bb + re;
		m.b = m.twoab + im;
		if (m.a * m.a + m.b * m.b > 16.0)
			break ;
		i++;
	}
	return (i);
}
