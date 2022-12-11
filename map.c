/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:27:22 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/11 18:56:39 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(char **map)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] == 'C')
			c++;
		i++;
		j++;
	}
	return (c);
}

void	check_character(char *c)
{
	int	linecount;
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] != 'E' && c[i] != 'P' && c[i] != 'C'
			&& c[i] != '1' && c[i] != '0' && c[i] != '\n')
			exit(0);
		i++;
	}
}

int	check_wall(char **map, char *filename)
{
	int		i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (map[count_line(filename) - 1][i])
	{
		if (map[count_line(filename) - 1][i] != '1' &&
			map[count_line(filename) - 1][i] != '\n')
			return (0);
			i++;
	}
	return (1);
}

int	main(void)
{
	int		fd;
	char	**map;
	int		i;

	fd = open("map.ber", O_RDONLY);
	map = read_map("map.ber");
	if (check_filename_ext("map.ber", "ber") == 0)
		return (0);
	if (!check_len(map))
		return (0);
	if (!check_wall(map, "map.ber"))
		return (0);
	i = 0;
	while (map[i])
	{
		check_character(map[i]);
		if (map[i][0] != '1')
			return (0);
		else if (map[i][ft_strlen(map[0]) - 2] != '1')
			return (0);
		ft_printf("%s", map[i]);
		i++;
	}
	close(fd);
}
