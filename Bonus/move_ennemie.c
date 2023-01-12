/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:38:39 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/12 20:29:44 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_path(t_game *game, char move)
{
	if (move == '1' || move == 'C' || move == 'M')
		return (0);
	else if (move == 'P')
	{
		kill_ennemie(game);
		return (1);
	}
	else
		return (1);
}

void	move_ennemie(t_game *game, int x, int y)
{
	int	move;

	move = rand() % 4;
	game->map.map[x][y] = '0';
	if (check_path(game, game->map.map[x][y - 1]) && move == 0)
		game->map.map[x][y - 1] = 'M';
	else if (check_path(game, game->map.map[x][y + 1]) && move == 1)
		game->map.map[x][y + 1] = 'M';
	else if (check_path(game, game->map.map[x + 1][y]) && move == 2)
		game->map.map[x + 1][y] = 'M';
	else if (check_path(game, game->map.map[x - 1][y]) && move == 3)
		game->map.map[x - 1][y] = 'M';
	else
	game->map.map[x][y] = 'M';
}

void	move(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (game->map.map[x][y] == 'M')
				move_ennemie(game, x, y);
		y++;
		}
	x++;
	}
}

int	movement(t_game *game)
{
	if (game->time % 4000 == 0)
	{
		move(game);
		put_elements(game);
	}
	game->time++;
	return (0);
}
