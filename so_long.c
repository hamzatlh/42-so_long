/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:48:24 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/29 03:54:02 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_game *game)
{
	game->background.img = mlx_xpm_file_to_image(game->mlx, "./assets/back.xpm",&game->background.x_img, &game->background.y_img);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/15.xpm", &game->wall.x_img, &game->wall.y_img);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, "./assets/7_1.xpm", &game->collectible.x_img, &game->collectible.y_img);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/12.xpm", &game->exit.x_img, &game->exit.y_img);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/0.xpm", &game->player.x_img,&game->player.y_img);
	game->exit_ouvert.img = mlx_xpm_file_to_image(game->mlx, "./assets/11.xpm", &game->exit_ouvert.x_img, &game->exit_ouvert.y_img);
}

void	backround(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < game->map.x * Sq)
	{
		y = 0;
		while (y < game->map.y * Sq)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->background.img, y, x);
			y += Sq;
		}
		x += Sq;
	}
}

void	put_elements(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.x)
	{
		y = 0;
		while (y < game->map.y)
		{
			if (game->map.map[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, y * Sq, x * Sq);
			else if (game->map.map[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->background.img, y * Sq, x * Sq);
			else if (game->map.map[x][y] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->exit.img, y * Sq, x * Sq);
				game->map.exit.x = x;
				game->map.exit.y = y;
			}
			else if (game->map.map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible.img, y * Sq, x * Sq);
			else if (game->map.map[x][y] == 'e')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_ouvert.img, y * Sq, x * Sq);
			else if (game->map.map[x][y] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->player.img, y * Sq, x * Sq);
				game->map.player.x = x;
				game->map.player.y = y;
			}
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_game game;

	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			ft_printf("Error\n finahowa FD.\n");
		game.count_C = 0;
		game.count_E = 0;
		game.count_P = 0;
		game.map.mv = 0;
		game.map.player.x = 0;
		game.map.player.y = 0;
		copy(av[1]);
		game.map.map = print_m(av[1], &game);
		game.map.y = ft_strlen(game.map.map[0]) - 1;
		game.map.x = count_line(av[1]);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.map.y * Sq, game.map.x * Sq, "so_long");
		put_images(&game);
		backround(&game);
		put_elements(&game);
		mlx_hook(game.win, 2, 0, ft_keypress, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("Error\nMap makynach\n");
	return (0);
}
