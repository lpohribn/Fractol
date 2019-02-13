/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:37:16 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/02 15:37:18 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_procent(double iter, double min_iter, double max_iter)
{
	if (iter == min_iter)
		return (0.0);
	if (iter == max_iter)
		return (1.0);
	return ((iter - min_iter) / (max_iter - min_iter));
}
