/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:06:44 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/23 23:00:47 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void ft_move_up(t_game *game)
{
	if (game->map.map[game->map.player.x - 1][game->map.player.y] != '1' && game->map.map[game->map.player.x - 1][game->map.player.y] != 'E')
		{
			if (game->map.map[game->map.player.x - 1][game->map.player.y] == '0')
			{
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
				game->map.player.x--;
			}
			else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
			{
				game->count_C--;
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
				game->map.player.x--;
				ft_printf("%d\n", game->count_C);
			}
		backround(game);
		put_elements(game);
		}
}

void ft_move_down(t_game *game)
{
	if (game->map.map[game->map.player.x + 1][game->map.player.y] != '1' && game->map.map[game->map.player.x + 1][game->map.player.y] != 'E')
		{
			if (game->map.map[game->map.player.x + 1][game->map.player.y] == '0')
			{
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
				game->map.player.x++;
			}
			else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
				{
					game->count_C--;
					game->map.map[game->map.player.x][game->map.player.y] = '0';
					game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
					game->map.player.x++;
					ft_printf("%d\n", game->count_C);
				}
		backround(game);
		put_elements(game);
		}
}

void ft_move_left(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y - 1] != '1' && game->map.map[game->map.player.x][game->map.player.y - 1] != 'E')
		{
			if (game->map.map[game->map.player.x][game->map.player.y - 1] == '0')
			{
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
				game->map.player.y--;
			}
			else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
				{
					game->count_C--;
					game->map.map[game->map.player.x][game->map.player.y] = '0';
					game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
					game->map.player.y--;
					ft_printf("%d\n", game->count_C);
				}
			backround(game);
			put_elements(game);
		}
}

void ft_move_right(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] != '1' && game->map.map[game->map.player.x][game->map.player.y + 1] != 'E')
		{
			if (game->map.map[game->map.player.x][game->map.player.y + 1] == '0')
			{
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
				game->map.player.y++;
			}
			else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
				{
					game->count_C--;
					game->map.map[game->map.player.x][game->map.player.y] = '0';
					game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
					game->map.player.y++;
					ft_printf("%d\n", game->count_C);
				}
			backround(game);
			put_elements(game);
		}
}

int	ft_keypress(int key, t_game *game)
{
	if (key == W || key == 126)
		ft_move_up(game);
	else if (key == A || key == 125)
		ft_move_down(game);
	else if (key == D || key == 124)
		ft_move_right(game);
	else if (key == S || key == 123)
		ft_move_left(game);
	return (0);
}