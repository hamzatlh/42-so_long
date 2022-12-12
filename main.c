/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:48:24 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/12 03:28:23 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.x * S,
			game->map.y * S, "so_long");
	img_init(game);
}

void	img_init(t_game *game)
{
	game->background.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/backround.xpm", &game->background.x_img,
			&game->background.y_img);
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &game->wall.x_img,
			&game->wall.y_img);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectible.xpm", &game->collectible.x_img,
			&game->collectible.y_img);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/door.xpm", &game->exit.x_img,
			&game->exit.y_img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &game->player.x_img,
			&game->player.y_img);
}

void	backround(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->background.img, x * S, y * S);
			x++;
		}
		y++;
	}
}

void	elements(t_game *game)
{
	int		x;
	int		y;
	char	c;

	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, x * S, y * S);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->background.img, x * S, y * S);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x * S, y * S);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, x * S, y * S);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, x * S, y * S);
}

int	main(void)
{
	t_game	game;

	elements(&game);
	game_init(&game);
	mlx_loop(game.mlx);
}
