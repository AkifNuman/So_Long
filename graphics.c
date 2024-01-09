/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:28:05 by bkas              #+#    #+#             */
/*   Updated: 2023/12/20 23:51:31 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_game *data, int width, int height)
{
	mlx_put_image_to_window(data->mlxpointer, data->winpointer, data->player,
		width * UNIT, height * UNIT);
	data->player_x = width;
	data->player_y = height;
}

void	image_control(t_game *data)
{
	if (!data->playerup || !data->playerdown || !data->playerleft
		|| !data->playerright || !data->wall || !data->exit
		|| !data->collectable || !data->collectable1 || !data->collectable2
		|| !data->collectable3 || !data->background)
	{
		ft_printf("XPM file not found.!");
		exit_point(data);
	}
}

void	images_in_game2(t_game *data, int i, int j)
{
	data->collectable = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/food.xpm", &i, &j);
	data->collectable1 = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/nami.xpm", &i, &j);
	data->collectable2 = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/usop.xpm", &i, &j);
	data->collectable3 = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/char.xpm", &i, &j);
	data->background = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/sand.xpm", &i, &j);
	image_control(data);
}

void	images_in_game(t_game *data)
{
	int	i;
	int	j;

	data->playerdown = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/down.xpm", &i, &j);
	data->playerup = mlx_xpm_file_to_image(data->mlxpointer, "textures/up.xpm",
			&i, &j);
	data->playerright = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/right.xpm", &i, &j);
	data->playerleft = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/left.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlxpointer, "textures/exit.xpm",
			&i, &j);
	data->wall = mlx_xpm_file_to_image(data->mlxpointer, "textures/wall.xpm",
			&i, &j);
	images_in_game2(data, i, j);
}

void	adding_graphics(t_game *data)
{
	int	height;
	int	width;
	int	whic;

	height = -1;
	whic = 0;
	mlx_clear_window(data->mlxpointer, data->winpointer);
	while (++height < data->map_height)
	{
		width = -1;
		while (data->map[height][++width])
		{
			mlx_put_image_to_window(data->mlxpointer, data->winpointer,
				data->background, width * UNIT, height * UNIT);
			if (data->map[height][width] == '1')
				mlx_put_image_to_window(data->mlxpointer, data->winpointer,
					data->wall, width * UNIT, height * UNIT);
			if (data->map[height][width] == 'P')
				place_player(data, width, height);
			if (data->map[height][width] == 'C')
				whic = adding_graphics_next(data, height, width, whic);
			if (data->control == 0)
				show_exit(data, data->exit_location_y, data->exit_location_x);
		}
	}
}
