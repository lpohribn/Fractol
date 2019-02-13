/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:00:42 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/05 18:00:44 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key1(int key, t_struct *s)
{
	if (key == 53)
		exit(0);
	if (key == 23)
		s->m.psyho = s->m.psyho == 0 ? 1 : 0;
	else if (key == 83 || key == 84 || key == 85 ||
		key == 86 || key == 87 || key == 88)
		ft_getcolor(key, s);
	else if (key == 24)
		s->m.max_iter += 1;
	else if (key == 27)
		s->m.max_iter -= 1;
	else if (key == 36)
		ft_info(s);
	else if (key == 18)
		s->m.c2 = 0xFFFFFF;
	else if (key == 19)
		s->m.c2 = 0x22D311;
	else if (key == 20)
		s->m.c2 = 0xa448FA;
	else if (key == 21)
		s->m.c2 = 0x09C7C5;
	else if (key == 49 && s->mouse.space == 1)
		s->mouse.space -= 1;
	else if (key == 49)
		s->mouse.space += 1;
}

int		ft_key(int key, t_struct *s)
{
	if (key == 123)
	{
		s->mouse.re_min += (s->mouse.re_max - s->mouse.re_min) * 0.1;
		s->mouse.re_max += (s->mouse.re_max - s->mouse.re_min) * 0.1;
	}
	else if (key == 124)
	{
		s->mouse.re_min -= (s->mouse.re_max - s->mouse.re_min) * 0.1;
		s->mouse.re_max -= (s->mouse.re_max - s->mouse.re_min) * 0.1;
	}
	else if (key == 126)
	{
		s->mouse.im_min += (s->mouse.im_max - s->mouse.im_min) * 0.1;
		s->mouse.im_max += (s->mouse.im_max - s->mouse.im_min) * 0.1;
	}
	else if (key == 125)
	{
		s->mouse.im_min -= (s->mouse.im_max - s->mouse.im_min) * 0.1;
		s->mouse.im_max -= (s->mouse.im_max - s->mouse.im_min) * 0.1;
	}
	else
		ft_key1(key, s);
	ft_image(s);
	return (0);
}
