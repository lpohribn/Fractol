/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:10:08 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/02 17:10:09 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_create_thread(t_struct *s)
{
	t_thread	t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		t[i].s = s;
		t[i].thread_id = i;
		pthread_attr_init(&t[i].thread_p);
		pthread_create(&t[i].thread, &t[i].thread_p, ft_draw_fractal, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i].thread, NULL);
		i++;
	}
	return (0);
}
