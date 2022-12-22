/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:06:44 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/22 01:49:26 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void ft_swap(char *a, char *b)
{
	char tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_move_up(t_game *game)
{
	if (game->map.map[game->map.player.x - 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x - 1][game->map.player.y], &game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x--;
	}
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
	{
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
		game->map.player.x--;
	}
	put_elements(game);

}

void ft_move_down(t_game *game)
{
	if (game->map.map[game->map.player.x+1][game->map.player.y] == 0)
	{
		ft_swap(&game->map.map[game->map.player.x + 1][game->map.player.y], &game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x++;
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
	{
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x-1][game->map.player.y] = 'P';
		game->map.player.x++;
	}
	put_elements(game);
}

void ft_move_left(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y-1] == 0)
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y - 1], &game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y--;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
	{
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
		game->map.player.y--;
	}
	put_elements(game);

}

void ft_move_right(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] == 0)
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y + 1], &game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y++;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
	{
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
		game->map.player.y++;
	}
	put_elements(game);

}

int	ft_keypress(int key, void *param)
{
	t_game *game;


	if (key == up || key == 126)
		ft_move_up(game);
	else if (key == down || key == 123)
		ft_move_down(game);
	else if (key == right || key == 124)
		ft_move_right(game);
	else if (key == left || key == 125)
		ft_move_left(game);
	mlx_clear_window(game->mlx, game->win);
	return (0);
}