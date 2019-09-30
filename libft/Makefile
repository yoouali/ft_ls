# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 21:34:28 by yabakhar          #+#    #+#              #
#    Updated: 2019/08/01 17:50:01 by yabakhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	= ft_atoi.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_sqrt.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putchar_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strclr.c\
	  ft_strcpy.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strnew.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strsplit.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_gword.c\
	  ft_get_len_int.c\
	  ft_memsub.c\
	  ft_lstlen.c\
	  ft_aff_lst.c\
	  ft_del.c\

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) libft.h
	@gcc $(FLG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
