/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:19:39 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/29 21:54:54 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
