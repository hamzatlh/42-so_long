/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:00:15 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/01 17:55:29 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_game *game, char s)
{
	if (s == 'u')
		game->player.img = mlx_xpm_file_to_image(game->mlx,
				"./assets/player_up.xpm", &game->player.x_img,
				&game->player.y_img);
	else if (s == 'l')
		game->player.img = mlx_xpm_file_to_image(game->mlx,
				"./assets/player_left.xpm", &game->player.x_img,
				&game->player.y_img);
	else if (s == 'd')
		game->player.img = mlx_xpm_file_to_image(game->mlx,
				"./assets/player_down.xpm", &game->player.x_img,
				&game->player.y_img);
	else if (s == 'w')
		game->player.img = mlx_xpm_file_to_image(game->mlx,
				"./assets/player.xpm", &game->player.x_img,
				&game->player.y_img);
}
