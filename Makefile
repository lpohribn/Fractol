# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:38:36 by lpohribn          #+#    #+#              #
#    Updated: 2017/11/12 14:25:06 by lpohribn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = my_libft/

SRC = main.c ft_mandelbrot.c ft_init.c ft_info.c ft_zoom_n_move.c ft_color.c ft_julia.c \
	ft_procent.c ft_re_im.c ft_burningship.c draw_fractal.c ft_tricorn.c ft_heart.c ft_celtic.c \
	ft_create_thread.c ft_grid.c ft_psyhodelic.c ft_keys.c ft_getcolor.c ft_info2.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

MINILIBX = -lmlx -framework OpenGL -framework AppKit

THREADS = -lpthread

all : $(NAME) 
	
$(NAME): $(OBJ)
	make -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(MINILIBX) $(THREADS) $(LIB)libft.a
	
%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)
	make clean -C $(LIB)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIB)

re : fclean all
