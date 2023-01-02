/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:38:39 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/02 01:23:36 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_ennemie(t_game *game, int x, int y)
{
	int	move;

	move = rand() % 4;
	game->map.map[x][y] = '0';
	if (move == 0 && game->map.map[x][y - 1] == '0')
		game->map.map[x][y - 1] = 'M';
	else if (move == 1 && game->map.map[x][y + 1] == '0')
		game->map.map[x][y + 1] = 'M';
	else if (move == 2 && game->map.map[x + 1][y] == '0')
		game->map.map[x + 1][y] = 'M';
	else if (move == 3 && game->map.map[x - 1][y] == '0')
		game->map.map[x - 1][y] = 'M';
	else
		game->map.map[x][y] = 'M';
}

void	move(t_game *game)
{
	int	x;
	int	y;

	if (game->time % 19 == 0)
	{
		x = 0;
		while (game->map.map[x])
		{
			y = 0;
			while (game->map.map[x][y])
			{
				if (game->map.map[x][y] == 'M')
					move_ennemie(game, x, y);
			}
			y++;
		}
		y = 0;
		x++;
	}
}
