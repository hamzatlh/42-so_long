# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 22:15:48 by htalhaou          #+#    #+#              #
#    Updated: 2022/12/02 18:01:58 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = so_long.c

NAME    = so_long

CFLAGS   = -Wall -Wextra -Werror libft/libft.a libft/ft_printf/libftprintf.a
	
RM        = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):
	$(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit
	./a.out
	
all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re