# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 17:15:39 by ielmakhf          #+#    #+#              #
#    Updated: 2022/02/04 17:15:52 by ielmakhf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC		= 	main.c mandelbrot.c hook.c julia.c julias.c issam.c clear_and_draw.c

OBJ		= $(SRC:.c=.o)

NAME 	= fractol

CFLAGS = -Wall -Wextra -Werror

FLAG	= -lmlx -framework OpenGL -framework AppKit

CC = @gcc

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft/
	@gcc $(OBJ) $(FLAG) libft/libft.a -o $(NAME)
	@echo "\033[92mDone for fractol\033[0m"

clean :
	@make clean -C ./libft/
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re : fclean all