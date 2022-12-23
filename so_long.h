/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:21 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/22 22:35:21 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "li/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# define Sq 40
# define W 13
# define A 1
# define S 0
# define D 2

typedef struct s_img
{
	void	*img;
	int		x_img;
	int		y_img;
}t_img;

typedef struct s_xy
{
	int	x;
	int y;
}t_xy;

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
	t_xy		player;
}t_map;

typedef struct s_count_elem
{
	int		count_c;
	int		count_e;
	int		count_p;
}t_count_elem;

typedef struct s_game
{
	void	*win;
	void	*mlx;
	int		collectibles;
	t_map	map;
	t_img	background;
	t_img	wall;
	t_img	collectible;
	t_img	exit;
	t_img	player;
}t_game;

int		check_filename_ext(char *filename, char *ext);
char	**read_map(char *filename);
char	*map_all(int df);
int		check_len(char **map);
int		check_wall(char **map, char *filename);
char	**print_m(char *filename);
void	put_images(t_game *game);
void	backround(t_game *game);
void	put_elements(t_game *game);
int		lentgh(char *line);
int		count_line(char *filename);
int		count_collect(char **map);
int		ft_keypress(int key, t_game *game);
#endif