/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:38:09 by bkas              #+#    #+#             */
/*   Updated: 2023/09/19 18:09:05 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	pac_screen(t_game *data)
{
	static int	i = 0;
	char		*line;
	int			x;
	int			y;

	x = 15;
	y = (data->map_height - 1) * UNIT + 15;
	line = ft_itoa(data->counter);
	mlx_string_put(data->mlxpointer, data->winpointer,
		x, y, 0x00FF00, "Step Count: ");
	mlx_string_put(data->mlxpointer, data->winpointer,
		x + 85, y, 0x00FF00, line);
	free(line);
	if (++i <= 14)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->close, data->player_x * UNIT, data->player_y * UNIT);
	else if (++i <= 28)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->player, data->player_x * UNIT, data->player_y * UNIT);
	else
		i = 0;
}

void	put_ghost(t_game *data)
{
	mlx_put_image_to_window(data->mlxpointer, data->winpointer,
		data->ghost, data->ghost_x * UNIT, data->ghost_y * UNIT);
}

int	enemy_move(t_game *data)
{
	adding_graphics(data);
	pac_screen(data);
	put_ghost(data);
	if (data->ghost_y == data->player_y
		&& data->ghost_x == data->player_x)
	{
		ft_printf("YOU LOSE..!");
		exit_point(data);
	}
	if (data->map[data->ghost_y][data->ghost_x] != 'E'
	&& data->map[data->ghost_y][data->ghost_x] != 'C')
		data->map[data->ghost_y][data->ghost_x] = '0';
	controls1(data);
	if (data->map[data->ghost_y][data->ghost_x] != 'E'
	&& data->map[data->ghost_y][data->ghost_x] != 'C')
		data->map[data->ghost_y][data->ghost_x] = 'N';
	return (1);
}
