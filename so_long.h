/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:21 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/13 19:00:20 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "li/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include<stdio.h>

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'p'
# define EXIT 'E'
# define S 40

typedef struct s_img
{
	void	*img;
	int		x_img;
	int		y_img;
}t_img;

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
}t_map;

typedef struct s_game
{
	void	*win;
	void	*mlx;
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

#endif