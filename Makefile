# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 22:15:48 by htalhaou          #+#    #+#              #
#    Updated: 2023/01/11 14:54:53 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =  mandatory/*.c

SRCS_BONUS	= bonus/*.c

NAME    = so_long

CFLAGS   = -Wall -Wextra -Werror 
	
RM        = rm -f

all:$(NAME)

$(NAME):
	@make -C li/
	$(CC) $(CFLAGS) $(SRCS)  -lmlx -framework OpenGL -framework AppKit li/libft.a -o $(NAME)


bonus:	
	@make -C li/
	$(CC) $(CFLAGS) $(SRCS_BONUS)  -lmlx -framework OpenGL -framework AppKit li/libft.a -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	@make fclean -C li/
	$(RM) $(NAME)

re:fclean all

.PHONY:fclean bonus all clean re