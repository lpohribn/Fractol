/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:22:27 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/07 20:22:29 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instruction(void)
{
	ft_putendl("---INSTRUCTIONS---");
	ft_putendl("ZOOM: scrolling mouse(UP, DOWN)\n");
	ft_putendl("MOVEMENT\nArrows: UP, DOWN, LEFT, RIGHT\n");
	ft_putendl("COUNT OF ITTERATIONS: + -\n");
	ft_putendl("COLORS OF FRACTALS: 1, 2, 3, 4, 5\n");
	ft_putendl("RESET: ENTER\n");
	ft_putendl("EXIT: esc\n");
}

int		ft_fractals(void)
{
	ft_putendl("The correct name of fractal:\n"
		"mandelbrot or -m\njulia or -j\nburningship or -b\n"
		"tricorn or -t\nheart or -h\nceltic or -c\ngridor -g\n");
	return (0);
}

int		ft_choose_fractal(char *str)
{
	if (!ft_strcmp(str, "mandelbrot") || !ft_strcmp(str, "-m"))
		return (1);
	if (!ft_strcmp(str, "julia") || !ft_strcmp(str, "-j"))
		return (2);
	if (!ft_strcmp(str, "burningship") || !ft_strcmp(str, "-b"))
		return (3);
	if (!ft_strcmp(str, "tricorn") || !ft_strcmp(str, "-t"))
		return (4);
	if (!ft_strcmp(str, "heart") || !ft_strcmp(str, "-h"))
		return (5);
	if (!ft_strcmp(str, "celtic") || !ft_strcmp(str, "-c"))
		return (6);
	if (!ft_strcmp(str, "grid") || !ft_strcmp(str, "-g"))
		return (7);
	return (0);
}
