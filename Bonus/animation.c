/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:07:08 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/14 01:07:45 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	anim(t_game *game)
{
	if (game->time % 4000 == 200)
	{
		update_player(game, 'r');
		backround(game);
		put_elements(game);
	}
	if (game->time % 4000 == 500)
	{
		update_player(game, 'u');
		backround(game);
		put_elements(game);
	}
	if (game->time % 4000 == 800)
	{
		update_player(game, 'l');
		backround(game);
		put_elements(game);
	}
	if (game->time % 4000 == 1100)
	{
		update_player(game, 'd');
		backround(game);
		put_elements(game);
	}	
}
