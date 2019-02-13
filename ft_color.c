/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:55:53 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/01 16:55:54 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_red(int color)
{
	return (color >> 16 & 0xFF);
}

int				ft_green(int color)
{
	return (color >> 8 & 0xFF);
}

int				ft_blue(int color)
{
	return (color & 0xFF);
}

static	int		ft_color(int color1, int color2, double procent)
{
	return (color1 + (color2 - color1) * procent);
}

int				ft_gradient(int color1, int color2, double procent)
{
	double red;
	double green;
	double blue;

	red = ft_color(ft_red(color1), ft_red(color2), procent);
	green = ft_color(ft_green(color1), ft_green(color2), procent);
	blue = ft_color(ft_blue(color1), ft_blue(color2), procent);
	return (red * 0x010000 + green * 0x000100 + blue * 0x000001);
}
