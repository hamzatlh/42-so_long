# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 22:15:48 by htalhaou          #+#    #+#              #
#    Updated: 2022/12/31 20:29:26 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = *.c

SRCS_BONUS	= *.c

NAME    = so_long

CFLAGS   = -Wall -Wextra -Werror 
	
RM        = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):
	$(CC) $(SRCS)  -lmlx -framework OpenGL -framework AppKit li/libft.a

bonus:	$(NAME)
		$(CC) $(SRCS)  -lmlx -framework OpenGL -framework AppKit li/libft.a

all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re