/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:27:22 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/29 22:14:21 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(char **map, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->count_c++;
			else if (map[i][j] == 'P')
				game->count_p++;
			else if (map[i][j] == 'E')
				game->count_e++;
			j++;
		}
		i++;
	}
	return (1);
}

void	check_epc(char **map, t_game *game)
{
	ft_printf("\n\nyou have %d collectibles\n", game->count_c);
	if (game->count_c < 1 || game->count_p != 1 || game->count_e != 1)
	{
		ft_printf("Error\n<<Duplicate charactere\
			or not enogh collectibles>> are Detected");
		exit(0);
	}
}

char	**read_map(char *filename)
{
	int		fd;
	char	linecount;
	int		i;
	char	**map;

	linecount = count_line(filename);
	map = (char **)malloc((linecount + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (!fd || fd <= 0)
		return (0);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close (fd);
	return (map);
}

void	check_character(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] != 'E' && c[i] != 'P' && c[i] != 'C'
			&& c[i] != '1' && c[i] != '0' && c[i] != '\n')
		{
			ft_printf("Error\nCheck Characters fail");
			exit(0);
		}
		i++;
	}
}

char	**print_m(char *filename, t_game *tmp)
{
	int		i;
	char	**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	map = read_map(filename);
	if (!check_filename_ext(filename, "ber") || \
	!check_len(map) || !check_wall(map, filename) || !count_collect(map, tmp))
	{
		ft_printf("Error\nCheck <<Wall || len || name || >> fail\n");
		exit (0);
	}
	check_epc(map, tmp);
	i = 0;
	while (map[i])
	{
		check_character(map[i]);
		if (map[i][0] != '1')
			return (0);
		else if (map[i][ft_strlen(map[0]) - 2] != '1')
			return (0);
		i++;
	}
	close(fd);
	return (map);
}
