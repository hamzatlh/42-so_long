/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:06:44 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/24 20:03:18 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void ft_move_up(t_game *game)
{
	if (game->map.map[game->map.player.x - 1][game->map.player.y] != '1')
		{
 				put_elements(game);
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
			if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
			{
				game->count_C--;
				game->map.map[game->map.player.x - 1][game->map.player.y] = '0';
 				put_elements(game);
			}
			if (game->count_C == 0)
			{
				game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
			}
			if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'e')
			{
				exit(0);
			}
			game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
			game->map.player.x--;
			game->map.mv++;
			put_elements(game);
		}
	ft_printf("\n-->%d steps -->%d collected \n ", game->map.mv, game->count_C);
}

void ft_move_down(t_game *game)
{
	if (game->map.map[game->map.player.x + 1][game->map.player.y] != '1')
		{		
				put_elements(game);
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
			if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
				{
					game->count_C--;
					game->map.map[game->map.player.x + 1][game->map.player.y] = '0';
 					put_elements(game);

				}
			if (game->count_C == 0)
				{
					game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
				}
			if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'e')
				{
					exit(0);
				}
			game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
			game->map.player.x++;
			game->map.mv++;
			put_elements(game);
		}
	ft_printf("\n-->%d steps -->%d collected \n ", game->map.mv, game->count_C);
}

void ft_move_left(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y - 1] != '1')
		{		
				put_elements(game);
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
			if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
				{
					game->count_C--;
					game->map.map[game->map.player.x][game->map.player.y - 1] = '0';
 					put_elements(game);
				}
			if (game->count_C == 0)
				{
					game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
				}
			if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'e')
				{
					exit(0);
				}
			game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
			game->map.player.y--;
			game->map.mv++;
			put_elements(game);
		}
	ft_printf("\n-->%d steps -->%d collected \n ", game->map.mv, game->count_C);
}

void ft_move_right(t_game *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] != '1')
		{		
				put_elements(game);
				game->map.map[game->map.player.x][game->map.player.y] = '0';
				game->map.map[game->map.exit.x][game->map.exit.y] = 'E';
			if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
				{
					game->count_C--;
					game->map.map[game->map.player.x][game->map.player.y + 1] = '0';
 					put_elements(game);
				}
			if (game->count_C == 0)
				{
					game->map.map[game->map.exit.x][game->map.exit.y] = 'e';
				}
			if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'e')
				{
					exit(0);
				}
			game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
			game->map.player.y++;
			game->map.mv++;
			put_elements(game);
		}
	ft_printf("\n-->%d steps -->%d collected \n ", game->map.mv, game->count_C);
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