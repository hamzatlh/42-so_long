/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:24:15 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/13 01:25:08 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	protection(t_game *game)
{
	if (!game->background.img || !game->wall.img
		|| !game->collectible.img || !game->exit.img
		|| !game->player.img || !game->exit_ouvert.img
		|| !game->ennemie.img)
	{
		ft_printf("img not found");
		exit_game(game);
	}
}
