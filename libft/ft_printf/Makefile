# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 17:12:30 by htalhaou          #+#    #+#              #
#    Updated: 2022/10/24 20:14:47 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
		ft_putchar.c\
		ft_putnbr_base.c\
		ft_putnbr.c\
		ft_putnbru.c\
		ft_putstr.c\
		ft_p.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@



$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

all:$(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re:fclean all


	