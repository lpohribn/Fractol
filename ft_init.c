/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:30:56 by lpohribn          #+#    #+#             */
/*   Updated: 2018/02/27 14:30:58 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(void)
{
	exit(1);
}

void	ft_image(t_struct *s)
{
	mlx_clear_window(s->mlx, s->win);
	ft_bzero(s->str, HEIGHT * WIDTH * 4);
	ft_create_thread(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	ft_infocolor(s);
}

void	ft_put_img(t_struct *s, int x, int y, int color)
{
	s->str[(y * WIDTH) + x] = color;
}

int		ft_mouse(int mouse, int x, int y, t_struct *s)
{
	if (mouse == 4)
	{
		s->mouse.zoom = 1.05;
		ft_zoom(s, x, y);
	}
	if (mouse == 5)
	{
		s->mouse.zoom = 0.9;
		ft_zoom(s, x, y);
	}
	ft_image(s);
	return (0);
}

void	ft_init(t_struct *s)
{
	int endian;

	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, HEIGHT, WIDTH, "lpohribn");
	s->img = mlx_new_image(s->mlx, HEIGHT, WIDTH);
	s->str = (int*)mlx_get_data_addr(s->img, &s->bp, &s->bl, &endian);
	mlx_hook(s->win, 2, 5, ft_key, s);
	mlx_hook(s->win, 6, 1L << 6, ft_move_mouse, s);
	mlx_hook(s->win, 17, 1L << 17, ft_exit, s);
	mlx_mouse_hook(s->win, ft_mouse, s);
}
