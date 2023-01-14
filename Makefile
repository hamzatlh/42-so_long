# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 22:15:48 by htalhaou          #+#    #+#              #
#    Updated: 2023/01/14 01:21:02 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  mandatory/check_map.c\
		mandatory/exit.c\
		mandatory/main.c\
		mandatory/map.c\
		mandatory/move_player.c\
		mandatory/path.c\
		mandatory/so_long.c\
		mandatory/update_player.c\

SRCS_BONUS	= bonus/check_map_bonus.c\
			bonus/enemie.c\
			bonus/exit_bonus.c\
			bonus/ft_put_bg_mv.c\
			bonus/main_bonus.c\
			bonus/map_bonus.c\
			bonus/move_ennemie.c\
			bonus/move_player_bonus.c\
			bonus/path_bonus.c\
			bonus/protection.c\
			bonus/so_long_bonus.c\
			bonus/update_player_bonus.c\
			bonus/animation.c

NAME    = so_long

NAME_BONUS = so_long_bonus

CFLAGS   = -Wall -Wextra -Werror 
	
RM        = rm -f

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJS)
	@make -C li/
	$(CC) $(CFLAGS) $(OBJS)  -lmlx -framework OpenGL -framework AppKit li/libft.a -o $(NAME)

bonus:$(NAME_BONUS)

$(NAME_BONUS):$(OBJS_BONUS)
	@make -C li/
	$(CC) $(CFLAGS) $(OBJS_BONUS)  -lmlx -framework OpenGL -framework AppKit li/libft.a -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	@make fclean -C li/
	$(RM) $(OBJS) $(OBJS_BONUS) $(NAME_BONUS)

re:fclean all bonus

.PHONY:fclean bonus all clean re