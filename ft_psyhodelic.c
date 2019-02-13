/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psyhodelic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:17:07 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/05 16:17:21 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_psyho(t_struct *s, int iter)
{
	int color;

	if (iter == 0)
		iter = 1;
	color = (int)iter * 2147483647 / (s->m.max_iter * iter * 0.1);
	return (color);
}
