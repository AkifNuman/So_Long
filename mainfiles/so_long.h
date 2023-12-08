/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:04:31 by bkas              #+#    #+#             */
/*   Updated: 2023/12/08 06:54:36 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "library/libft/libft.h"
# include "library/printf/ft_printf.h"
# include "library/get_next_line/get_next_line.h"
# include "library/minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>

# define UNIT 128 /////used;
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct l_index
{
	int	i; /////////used;
	int	j; /////////used;
	int	k;
}	t_index;

typedef struct l_start
{
	int		map_height;  ///used;
	int		map_width;	 ///used;
	int		colltot; /////used;
	int 	collcounter;
	int		counter;
	int		control;	///used;
	int		player_x;	///used;
	int		player_y;	///used;
	
	char	**map;     //////used;
	char	*maplocation;   //////////used;

	void 	*background;	///used;
	void	*wall;
	void	*player;		////used;
	void	*playerup;		////used;
	void	*playerdown;    ////used;
	void	*playerright;	////used;
	void	*playerleft;	////used;
	void	*exit;			///used;
	void	*collectable;	///used;
	void 	*collectable1;	///used;
	void	*collectable2;	///used;
	void	*collectable3;	///used;
	void	*mlxpointer;
	void	*winpointer;
	t_index	index;
}	t_game;

int		exit_point(t_game *data);
int		controls_working(int command, t_game *data);
int		collectable_counter(char *str);

void	ber_control(char *mapname);
void	txt_control(char *mapname);
void	map_control(char *mapname, t_game *data);
void	wall_control(t_game *data);
void	map_processing(t_game *data);
void	map_reading(t_game *data);
void 	show_exit(t_game *data, int width, int height);
void	error_message(char *msg);
void	images_in_game(t_game *data);
void	image_control(t_game *data);
void	placeholder(t_game *data, int x, int y);
void	adding_graphics(t_game *data);
void	place_player(t_game *data, int width, int height);
void	map_bug(t_game *data);
void	escape_line(t_game *data);
void	mlx_images_free(t_game *data);

#endif