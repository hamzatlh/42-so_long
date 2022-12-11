/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:21 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/11 19:10:24 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "li/libft.h"
# include <fcntl.h>
# include <mlx.h>

int		check_filename_ext(char *filename, char *ext);
char	**read_map(char *filename);
char	*map_all(int df);
int		check_len(char **map);
int		check_wall(char **map, char *filename);
int		main(void);

#endif