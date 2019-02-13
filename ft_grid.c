/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:19:20 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/06 17:39:47 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_grid(t_fractal j, double re, double im)
{
	int i;

	i = 0;
	j.a = sin(re);
	j.b = cos(im);
	while (i < j.max_iter)
	{
		j.aa = fabs(j.a * j.a);
		j.bb = fabs(j.b * j.b);
		j.twoab = fabs(2.0 * j.a * j.b);
		j.a = j.aa - j.bb + j.re;
		j.b = j.twoab + j.im;
		if (j.a * j.a + j.b * j.b > 16.0)
			break ;
		i++;
	}
	return (i);
}
