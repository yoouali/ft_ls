# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 19:55:13 by yabakhar          #+#    #+#              #
#    Updated: 2019/10/10 22:29:54 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Werror -Wextra

SRCS = 	arg.c\
		arg2.c\
		data.c\
		error.c\
		main.c\
		ls.c\
		sort_data.c\
		color.c\
		swap_more_data.c\
		get_prem.c\
		form.c\
		sort.c\
		free.c\
		print.c\
		ls2.c\
		ls3.c

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) ls.h
	@make -C libft
	@gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m$(NAME) created\n\033[0m"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all
