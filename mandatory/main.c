/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:22:33 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/12 21:57:56 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_complete(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		check_character(map[i]);
		if (map[i][0] != '1')
		{
			ft_printf("Error\nCheck <<Wall>>");
			exit (0);
		}
		else if (map[i][ft_strlen(map[0]) - 2] != '1')
		{
			ft_printf("Error\nCheck <<Wall>>");
			exit (0);
		}
		i++;
	}
}

void	init(t_game *game)
{
		game->count_c = 0;
		game->count_e = 0;
		game->count_p = 0;
		game->map.mv = 0;
		game->map.player.x = 0;
		game->map.player.y = 0;
		game->wind_x = 0;
		game->wind_y = 0;
}

void	game_initial(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.y * SQ,
			game->map.x * SQ, "so_long");
	put_images(game);
	backround(game);
	put_elements(game);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_printf("Error\ninvalid FD\n");
			exit (0);
		}
		copy(av[1]);
		init(&game);
		game.map.map = print_m(av[1], &game);
		game.map.y = ft_strlen(game.map.map[0]) - 1;
		game.map.x = count_line(av[1]);
		game_initial(&game);
		mlx_hook(game.win, 2, 0, ft_keypress, &game);
		mlx_hook(game.win, 17, 0, exit_game, &game);
		mlx_loop(game.mlx);
	}
	ft_printf("Error\nMap makynach\n");
	return (0);
}
