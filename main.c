/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:17:45 by lpohribn          #+#    #+#             */
/*   Updated: 2018/02/27 14:17:47 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_steps(t_struct s)
{
	ft_info(&s);
	ft_init(&s);
	ft_getcolor(0, &s);
	ft_image(&s);
	mlx_loop(s.mlx);
}

void	ft_multiprocess(t_struct *s, char **str)
{
	int ret;

	ret = fork();
	if (ret == 0)
		execv("fractol", str);
	if (ret > 0)
		s->name = ft_choose_fractal(str[0]);
	else
		ft_putendl("error");
}

int		main(int ac, char **av)
{
	t_struct s;

	if (ac == 1 || ac > 3)
	{
		ft_putendl("usage: ./fractol fractol1 fractol2");
		return (ft_fractals());
	}
	if (ac == 3)
		ft_multiprocess(&s, &av[1]);
	else
		s.name = ft_choose_fractal(av[1]);
	if (s.name == 0)
	{
		ft_putendl("WRONG NAME\n");
		return (ft_fractals());
	}
	if (ac == 2)
		instruction();
	ft_steps(s);
	return (0);
}
