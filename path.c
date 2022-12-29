/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:04:53 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/29 03:53:41 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy(char *filename)
{
	int		fd;
	char	linecount;
	int		i;
	char	**copy_map;

	linecount = count_line(filename);
	copy_map = (char **)malloc((linecount + 1) * sizeof(char *));
	if (!copy_map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (1)
	{
		copy_map[i] = get_next_line(fd);
		if (!copy_map[i])
			break ;
		i++;
	}
	if (!check_map_path(copy_map))
	{
		ft_printf("hhh");
		exit(0) ;
	}
	close (fd);
	return (copy_map);
}

void	get_posi(char **copy_map, int x, int y, int *i)
{
	if (copy_map[x][y - 1] == '0' || copy_map[x][y - 1] == 'C')
		{
			copy_map[x][y - 1] = 'P';
			*i = 1;
		}
	if (copy_map[x][y + 1] == '0' || copy_map[x][y + 1] == 'C')
		{
			copy_map[x][y + 1] = 'P';
			*i = 1;
		}
	if (copy_map[x - 1][y] == '0' || copy_map[x - 1][y] == 'C')
		{
			copy_map[x - 1][y] = 'P';
			*i = 1;
		}
	if (copy_map[x + 1][y] == '0' || copy_map[x + 1][y] == 'C')
		{
			copy_map[x + 1][y] = 'P';
			*i = 1;
		}
}

void	path(char **copy_map)
{
	int	i;
	int	x;
	int	y;

	i = 1;
	y = 0;
	while (i)
	{
		i = 0;
		x = 0;
		while (copy_map[x])
		{
			while (copy_map[x][y])
			{
				if (copy_map[x][y] == 'P')
					get_posi(copy_map, x, y, &i);
				y++;
			}
			y = 0;
			x++;
		}
	}
}

char **check_map_path(char **copy_map)
{
	path(copy_map);
	int i = 0;
	int j = 0;
	while (copy_map[i])
	{	ft_printf("%s", copy_map[i]);
		while(copy_map[i][j])
		{
			if(copy_map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (copy_map);
}
