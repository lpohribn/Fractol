/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:19:20 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/07 17:19:21 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_getcolor(int key, t_struct *s)
{
	s->m.red = ft_red(s->m.c2);
	s->m.green = ft_green(s->m.c2);
	s->m.blue = ft_blue(s->m.c2);
	if (key == 83 && s->m.red > 0)
		s->m.red--;
	if (key == 86 && s->m.red < 255)
		s->m.red++;
	if (key == 84 && s->m.green > 0)
		s->m.green--;
	if (key == 87 && s->m.green < 255)
		s->m.green++;
	if (key == 85 && s->m.blue > 0)
		s->m.blue--;
	if (key == 88 && s->m.blue < 255)
		s->m.blue++;
	s->m.c2 = (s->m.red << 16 | s->m.green << 8 | s->m.blue);
}
