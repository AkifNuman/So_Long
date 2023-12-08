/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:21:43 by bkas              #+#    #+#             */
/*   Updated: 2023/09/21 11:47:49 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "library/libft/libft.h"
# include "library/minilibx/mlx.h"
# include "library/get_next_line/get_next_line.h"
# include "library/printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>

# define UNIT 32
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct l_index
{
	int	i;
	int	j;
	int	k;
	int	p;
	int	e;
	int	n;
}	t_index;

typedef struct l_game
{
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		ghost_x;
	int		ghost_y;
	int		collectables;
	int		counter;
	int		enemy_speed;

	char	**map;
	char	*maplocation;

	void	*mlxpointer;
	void	*winpointer;
	void	*player;
	void	*playerup;
	void	*playerdown;
	void	*playerleft;
	void	*playerright;
	void	*ghost;
	void	*ghost_right;
	void	*ghost_left;
	void	*close;
	void	*collectable;
	void	*exit;
	void	*wall;
	t_index	index;
}	t_game;

int		enemy_move(t_game *data);
int		wall_check(t_game *data);
int		controls_working(int command, t_game *data);
int		exit_point(t_game *data);
int		enemy_run(t_game *data);
int		controls1(t_game *data);

void	error_message(char *msg);
void	ber_control(char *mapname);
void	txt_control(char *mapname);
void	map_control(char *mapname, t_game *data);
void	map_reading(t_game *data);
void	wall_control(t_game *data);
void	adding_graphics(t_game *data);
void	image_control(t_game *data);
void	place_player(t_game *data, int width, int height);
void	images_in_game(t_game *data);
void	placeholder(t_game *data, int x, int y);
void	map_bug(t_game *data);
void	map_processing(t_game *data);
void	escape_line(t_game *data);
void	find_enemy_location(t_game *data);
void	mlx_functions(t_game *data);
void	put_ghost(t_game *data);
void	controls2(t_game *data);
void	controls3(t_game *data);
void	escape_line(t_game *data);
void	mlx_images_free(t_game *data);
void	pac_screen(t_game *data);

#endif