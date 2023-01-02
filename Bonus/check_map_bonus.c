/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:19:35 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/01 18:36:39 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_filename_ext(char *filename, char *ext)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		exit (0);
	return (ft_strncmp(ext, dot + 1, 3) == 0);
}

int	count_line(char *filename)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (-1);
	count = 0;
	while (1)
	{			
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free (line);
	}
	close (fd);
	return (count);
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

int	lentgh(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
				i++;
	return (i);
}

int	check_len(char **map)
{
	int		i;
	int		len;

	i = 0;
	len = lentgh(map[i]);
	while (map[i])
	{
		if (lentgh(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}
