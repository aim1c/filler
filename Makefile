# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 16:00:48 by masprigg          #+#    #+#              #
#    Updated: 2019/04/03 23:46:00 by fsnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fsnow-be.filler

SRC = check_position.c delmaps.c heat_map.c main.c read_map_token.c

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean
	gcc -c -Wall -Wextra -Werror -I libft $(SRC)
	gcc -o $(NAME) *.o -I libft -L libft/ -lft
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
