/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bg_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:26:15 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/12 22:05:35 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_bg_mv(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->map.map[0]))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->background.img, i * 40, 0);
		i++;
	}
}
