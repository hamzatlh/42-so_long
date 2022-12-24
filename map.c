/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:27:22 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/24 22:57:01 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(char **map, t_game *tmp)
{
	int		i;
	int		j;
	int		count_e;
	int		count_p;

	count_e = 0;
	count_p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				tmp->count_C++;
			else if (map[i][j] == 'P')
				count_p++;
			else if (map[i][j] == 'E')
				count_e++;
			j++;
		}
		i++;
	}
	printf("%d\n", tmp->count_C);
	if (tmp->count_C < 1 || count_p != 1 || count_e != 1)
		{
			ft_printf("Error\n<<Duplicate charactere or not enogh collectibles>> are Detected");
			exit(0);
		}
	return (1);
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
			{
				ft_printf("Error\nCheck Character fail");	
				exit(0);
			}
		i++;
	}
}

int	lentgh(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
				i++;
	return (i);
}

char	**print_m(char *filename, t_game *tmp)
{
	int		i;
	char **map;
	int		fd;
	fd = open(filename, O_RDONLY);
	map = read_map(filename);
	if (!check_filename_ext(filename, "ber") || !check_len(map) || !check_wall(map, filename))
		{
			ft_printf("Error\nCheck <<Wall || len || name>> fail");
			exit (0);
		}
	if (!count_collect(map, tmp))
		return (0);
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
