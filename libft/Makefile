# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 12:56:38 by wqarro-v          #+#    #+#              #
#    Updated: 2018/12/09 17:08:27 by wqarro-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

HEAD = libft.h ft_printf.h

all: $(NAME)
$(NAME):
	gcc -c $(SRCS) -I $(HEAD)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(LIB) $(NAME)

re: fclean all
