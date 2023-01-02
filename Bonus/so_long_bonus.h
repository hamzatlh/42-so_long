/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:21 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/02 01:51:07 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../li/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# define SQ 40
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_img
{
	void	*img;
	int		x_img;
	int		y_img;
	void	*p;
}t_img;

typedef struct s_xy
{
	int	x;
	int	y;
}t_xy;

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
	int			mv;
	t_xy		exit;
	t_xy		exit_ouvert;
	t_xy		player;
	t_xy		player_down;
	t_xy		player_up;
	t_xy		player_left;
	t_xy		ennemie;
	t_xy		queue;

}t_map;

typedef struct s_game
{
	void	*win;
	void	*mlx;
	int		count_c;
	int		count_p;
	int		count_e;
	int		wind_x;
	int		wind_y;
	int		time;
	t_img	ennemie;
	t_map	map;
	t_img	background;
	t_img	wall;
	t_img	collectible;
	t_img	exit;
	t_img	player;
	t_img	player_down;
	t_img	player_left;
	t_img	player_up;
	t_img	exit_ouvert;
}t_game;

int		check_filename_ext(char *filename, char *ext);
char	**read_map(char *filename);
int		check_len(char **map);
int		check_wall(char **map, char *filename);
char	**print_m(char *filename, t_game *tmp);
void	put_images(t_game *game);
void	backround(t_game *game);
int		lentgh(char *line);
int		count_line(char *filename);
int		count_collect(char **map, t_game *tmp);
int		ft_keypress(int key, t_game *game);
void	exit_game(t_game *game);
int		check_map_path(char **copy_map);
char	**copy(char *filename);
void	init(t_game *game);
void	game_initial(t_game *game);
void	check_epc(char **map, t_game *game);
void	put_exit(t_game *game, int x, int y);
void	pu_2(t_game *game, int x, int y);
void	put_elements(t_game *game);
void	update_player(t_game *game, char s);
void	ft_won(t_game *game);
void	kill_ennemie(t_game *game);
void	move(t_game *game);
int		movement(t_game *game);

#endif