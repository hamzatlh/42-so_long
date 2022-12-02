/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:19:35 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/02 18:11:06 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"

int	*check_filename_ext(char *filename, char *ext)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	if (ft_strncmp(ext, dot + 1, 3))
		return (1);
}

char	**check_map(char *filename)
{
	int		fd;
	char	**map;

	if (!check_filename_ext(filename, "ber"))
		return (NULL);
	fd = open("filename", O_RDONLY);
	map = read_map(fd);
}
