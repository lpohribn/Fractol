/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:12:49 by lpohribn          #+#    #+#             */
/*   Updated: 2018/02/27 14:12:51 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define THREADS 8

# include "my_libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>

typedef	struct		s_mouse
{
	double			re_min;
	double			im_min;
	double			re_max;
	double			im_max;
	double			zoom;
	double			space;
}					t_mouse;

typedef	struct		s_fractal
{
	double			a;
	double			b;
	double			aa;
	double			bb;
	double			twoab;
	double			re;
	double			im;
	int				max_iter;
	int				c1;
	int				c2;
	int				psyho;
	int				red;
	int				blue;
	int				green;
}					t_fractal;

typedef struct		s_struct
{
	int				name;
	void			*mlx;
	void			*win;
	void			*img;
	int				*str;
	int				bp;
	int				bl;
	t_fractal		m;
	t_mouse			mouse;
}					t_struct;

typedef	struct		s_thread
{
	pthread_t		thread;
	pthread_attr_t	thread_p;
	int				thread_id;
	t_struct		*s;
}					t_thread;

double				ft_get_im(t_struct *s, double y);
double				ft_get_re(t_struct *s, double x);
int					ft_gradient(int color1, int color2, double procent);
double				ft_procent(double iter, double min_iter, double max_iter);
void				ft_put_img(t_struct *s, int x, int y, int color);
void				ft_info(t_struct *s);
void				*ft_draw_fractal(void *param);
int					ft_mandelbrot(t_fractal m, double re, double im);
int					ft_burningship(t_fractal m, double re, double im);
int					ft_julia(t_fractal j, double re, double im);
int					ft_celtic(t_fractal m, double re, double im);
int					ft_tricorn(t_fractal m, double re, double im);
int					ft_heart(t_fractal m, double re, double im);
void				ft_init(t_struct *s);
int					ft_move_mouse(int x, int y, t_struct *s);
void				ft_zoom(t_struct *s, int mouse_x, int mouse_y);
int					ft_create_thread(t_struct *s);
int					ft_grid(t_fractal m, double re, double im);
int					ft_red(int color);
int					ft_blue(int color);
int					ft_green(int color);
int					ft_psyho(t_struct *s, int iter);
int					ft_key(int key, t_struct *s);
void				ft_image(t_struct *s);
void				instruction(void);
int					ft_exit(void);
void				ft_getcolor(int key, t_struct *s);
void				ft_infocolor(t_struct *s);
int					ft_choose_fractal(char *str);
int					ft_fractals(void);
void				instruction(void);

#endif
