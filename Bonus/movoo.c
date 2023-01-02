/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movoo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:41:35 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/02 01:52:56 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	movement(t_game *game)
{
	int			x;
	int			y;

	if (game->count_c >= 0)
	{
		put_elements(game);
		move(game);
	}
	else
		exit_game(game);
	return (0);
}
