/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:04:31 by bkas              #+#    #+#             */
/*   Updated: 2023/12/21 11:34:20 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "library/get_next_line/get_next_line.h"
# include "library/libft/libft.h"
# include "library/minilibx/mlx.h"
# include "library/printf/ft_printf.h"
# include <fcntl.h>

# define UNIT 128
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct l_index
{
	int		i;
	int		j;
	int		k;
}			t_index;

typedef struct l_start
{
	int		map_height;
	int		map_width;
	int		collcounter;
	int		exit_loc_all_control;
	int		counter;
	int		control;
	int		player_x;
	int		player_y;
	int		exit_location_x;
	int		exit_location_y;

	char	**map;
	char	*maplocation;

	void	*background;
	void	*wall;
	void	*player;
	void	*playerup;
	void	*playerdown;
	void	*playerright;
	void	*playerleft;
	void	*exit;
	void	*collectable;
	void	*collectable1;
	void	*collectable2;
	void	*collectable3;
	void	*mlxpointer;
	void	*winpointer;
	t_index	index;
}			t_game;

int			exit_point(t_game *data);
int			controls_working(int command, t_game *data);
int			collectable_counter(char *str);

void		ber_control(char *mapname);
void		txt_control(char *mapname);
void		map_control(char *mapname, t_game *data);
void		wall_control(t_game *data);
void		exit_location_total(t_game *data);
void		map_processing(t_game *data);
void		map_reading(t_game *data);
void		show_exit(t_game *data, int width, int height);
void		error_message(char *msg);
void		images_in_game(t_game *data);
void		image_control(t_game *data);
void		placeholder(t_game *data, int x, int y);
void		adding_graphics(t_game *data);
int			adding_graphics_next(t_game *data, int height, int width, int whic);
void		place_player(t_game *data, int width, int height);
void		map_bug(t_game *data);
void		map_bug2(t_game *data);
void		escape_line(t_game *data);
void		mlx_images_free(t_game *data);
int			exit_location(char *maplocation);

#endif