/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:37:42 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/01 22:41:12 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	kill_ennemie(t_game *game)
{
	ft_printf("sorry");
	put_elements(game);
	exit_game(game);
}

void	ft_won(t_game *game)
{
	ft_printf("\n\n\n\n\nCongratulations bro !! you win\n\n\n\n\n");
	exit_game(game);
}
