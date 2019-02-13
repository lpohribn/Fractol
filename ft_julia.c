/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:53:57 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/01 16:54:02 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_fractal j, double re, double im)
{
	int i;

	i = 0;
	j.a = re;
	j.b = im;
	while (i < j.max_iter)
	{
		j.aa = j.a * j.a;
		j.bb = j.b * j.b;
		j.twoab = 2.0 * j.a * j.b;
		j.a = j.aa - j.bb + j.re;
		j.b = j.twoab + j.im;
		if (j.a * j.a + j.b * j.b > 16.0)
			break ;
		i++;
	}
	return (i);
}
