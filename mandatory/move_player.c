/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:06:44 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/12 20:31:45 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	if (game->map.map[game->map.player.x - 1][game->map.player.y] != '1')
	{
		put_elements(game);
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
		if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
		{
			game->count_c--;
			game->map.map[game->map.player.x - 1][game->map.player.y] = '0';
			put_elements(game);
		}
		if (game->count_c == 0)
			game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
		if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'e')
		{
			ft_printf("\n\n\n\n\nCongratulations bro !! you win\n\n\n\n\n");
			exit(0);
		}
		update_player(game, 'u');
		game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
		game->map.player.x--;
		game->map.mv++;
		put_elements(game);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map.map[game->map.player.x + 1][game->map.player.y] != '1')
	{		
		put_elements(game);
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
		if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
		{
			game->count_c--;
			game->map.map[game->map.player.x + 1][game->map.player.y] = '0';
			put_elements(game);
		}
		if (game->count_c == 0)
			game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
		if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'e')
		{
			ft_printf("\n\n\n\n\nCongratulations bro !! you win\n\n\n\n\n");
			exit(0);
		}
		update_player(game, 'd');
		game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
		game->map.player.x++;
		game->map.mv++;
		put_elements(game);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y - 1] != '1')
	{		
		put_elements(game);
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
		if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
		{
			game->count_c--;
			game->map.map[game->map.player.x][game->map.player.y - 1] = '0';
			put_elements(game);
		}
		if (game->count_c == 0)
			game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
		if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'e')
		{
			ft_printf("\n\n\n\n\nCongratulations bro !! you win\n\n\n\n\n");
			exit(0);
		}
		update_player(game, 'l');
		game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
		game->map.player.y--;
		game->map.mv++;
		put_elements (game);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] != '1')
	{		
		put_elements(game);
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
		if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
		{
			game->count_c--;
			game->map.map[game->map.player.x][game->map.player.y + 1] = '0';
			put_elements(game);
		}
		if (game->count_c == 0)
			game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
		if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'e')
		{
			ft_printf("\n\n\n\n\nCongratulations bro !! you win\n\n\n\n\n");
			exit(0);
		}
		update_player(game, 'w');
		game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
		game->map.player.y++;
		game->map.mv++;
		put_elements(game);
	}
}

int	ft_keypress(int key, t_game *game)
{
	if (key == ESC)
	{
		ft_printf("\n\n\n\n\nwhat the fuck are you doing bro !!!?\n\n\n\n\n");
		exit_game(game);
	}
	else if (key == W || key == 126)
		ft_move_up(game);
	else if (key == S || key == 125)
		ft_move_down(game);
	else if (key == D || key == 124)
		ft_move_right(game);
	else if (key == A || key == 123)
		ft_move_left(game);
	ft_printf("\n-->%d Steps -->%d To Collecte \n ", game->map.mv, game->count_c);
	return (0);
}
