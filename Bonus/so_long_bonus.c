/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:48:24 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/12 22:44:13 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_images(t_game *game)
{
	game->background.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/back.xpm", &game->background.x_img,
			&game->background.y_img);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./textures/15.xpm",
			&game->wall.x_img, &game->wall.y_img);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/7_1.xpm", &game->collectible.x_img,
			&game->collectible.y_img);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./textures/12.xpm",
			&game->exit.x_img, &game->exit.y_img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/p_right.xpm", &game->player.x_img,
			&game->player.y_img);
	game->exit_ouvert.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/11.xpm", &game->exit_ouvert.x_img,
			&game->exit_ouvert.y_img);
	game->ennemie.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/ennemie.xpm", &game->ennemie.x_img,
			&game->ennemie.y_img);
}

void	backround(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.x * SQ)
	{
		y = 0;
		while (y < game->map.y * SQ)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->background.img, y, x + 40);
			y += SQ;
		}
		x += SQ;
	}
}

void	put_elements(t_game *game)
{
	int		x;
	int		y;
	char	*str;
	char	*num;

	x = 0;
	while (x < game->map.x)
	{
		y = 0;
		while (y < game->map.y)
		{
			put_exit(game, x, y);
			pu_2(game, x, y);
			y++;
		}
		x++;
	}
	num = ft_itoa(game->map.mv);
	str = ft_strjoin_gnl(ft_strdup_gnl("number of moves : "), num);
	ft_put_bg_mv(game);
	mlx_string_put(game->mlx, game->win, game->wind_x * SQ + 10,
		game->wind_y * SQ + 10, 0xFF00FFFF, str);
	free (num);
	free (str);
}

void	put_exit(t_game *game, int x, int y)
{
	if (game->map.map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, y * SQ, x * SQ + 40);
	else if (game->map.map[x][y] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->background.img, y * SQ, x * SQ + 40);
	else if (game->map.map[x][y] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, y * SQ, x * SQ + 40);
		game->map.exit.x = x;
		game->map.exit.y = y;
	}
}

void	pu_2(t_game *game, int x, int y)
{
	if (game->map.map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, y * SQ, x * SQ + 40);
	else if (game->map.map[x][y] == 'e')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_ouvert.img, y * SQ, x * SQ + 40);
	else if (game->map.map[x][y] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, y * SQ, x * SQ + 40);
		game->map.player.x = x;
		game->map.player.y = y;
	}
	else if (game->map.map[x][y] == 'M')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->ennemie.img, y * SQ, x * SQ + 40);
		game->map.ennemie.x = x;
		game->map.ennemie.x = y;
	}
}
