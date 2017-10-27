# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 17:36:07 by dbessmer          #+#    #+#              #
#    Updated: 2017/02/24 13:55:02 by dbessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	filler

LIBFT = ./libft/libft.a

PRINTF = ./libft/ft_printf/libftprintf.a

SRC = 	main.c \
		map.c \
	  	filler.c \
	  	find_players.c \
	  	cover_field.c \
	  	make_diagonal.c \
	  	helpers.c \
	  	tests.c \
	    clear_data.c \

FLAGS = -Wall -Wextra -Werror

OBJ     = $(SRC:.c=.o)

all     : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
	    gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $<

$(LIBFT)  :
	    make -C libft/

$(PRINTF)  :
	    make -C libft/ft_printf/

lclean  :
	    make -C libft/ clean
	    make -C libft/ft_printf/ clean

clean   : lclean
	    rm -f $(OBJ)

fclean  : clean
	    rm -f $(NAME)
		rm -f libft/libft.a
		rm -f libft/ft_printf/libftprintf.a

re: fclean all
