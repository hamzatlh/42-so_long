/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:19:35 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/15 13:20:14 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
