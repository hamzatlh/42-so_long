# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:16:33 by htalhaou          #+#    #+#              #
#    Updated: 2023/01/09 21:54:14 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=  ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_calloc.c \
	ft_strrchr.c \
	ft_strlen.c \
	ft_atoi.c \
	ft_strtrim.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_itoa.c    \
	ft_split.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	print/ft_printf.c \
	print/ft_putchar.c \
	print/ft_putnbr_base.c \
	print/ft_putnbr.c \
	print/ft_putnbru.c \
	print/ft_putstr.c \
	print/ft_p.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
            
SRCS_BONUS	= ft_lstnew_bonus.c \
      ft_lstadd_front_bonus.c \
      ft_lstsize_bonus.c \
      ft_lstlast_bonus.c \
      ft_lstadd_back_bonus.c \
      ft_lstdelone_bonus.c \
      ft_lstclear_bonus.c \
      ft_lstiter_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME    = libft.a

CC        = gcc

CFLAGS    = -Wall -Wextra -Werror

RM        = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
			
$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)
			
bonus:$(NAME) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)

all:$(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: fclean all clean re