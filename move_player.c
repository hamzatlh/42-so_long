/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:06:44 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/21 23:44:00 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void ft_swap(char *a, char *b)
{
	char *temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_move_up(t_game *game)
{
	if (game->map.map[game->map.player.x-1][game->map.player.y] == 0)
	{
		ft_swap(game->map.map[game->map.player.x-1][game->map.player.y], game->map.map[game->map.player.x][game->map.player.y]);
	}
	else if (game->map.map[game->map.player.x-1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y];
		game->map.map[game->map.player.x-1][game->map.player.y] == "P";
		game->map.player.x--;
	}
}

void ft_down_up(t_game *game)
{
	if (game->map.map[game->map.player.x+1][game->map.player.y] == 0)
	{
		ft_swap(game->map.map[game->map.player.x+1][game->map.player.y], game->map.map[game->map.player.x][game->map.player.y]);
	}
	else if (game->map.map[game->map.player.x+1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y];
		game->map.map[game->map.player.x-1][game->map.player.y] == "P";
		game->map.player.x++;
	}
}
