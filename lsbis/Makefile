# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 18:02:51 by tcabon            #+#    #+#              #
#    Updated: 2015/02/05 17:16:13 by tcabon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = 		aff_l.c \
			argcheck.c \
			ft_error.c \
			ft_rights.c \
			init_struct.c \
			main.c \
			mainevent.c \
			ft_nbrlen.c \
			ft_is_dir.c \
			tri_ascii.c \
			tri_r.c \
			tri_t.c \
			ft_stat_l.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(OBJ) -L libft -lft -o $(NAME) -g

proper: $(NAME) clean

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

%.o: %.c
	gcc -c $< -o $@
