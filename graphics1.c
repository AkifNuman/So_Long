/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:28:05 by bkas              #+#    #+#             */
/*   Updated: 2023/12/12 14:38:37 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	adding_graphics_next(t_game *data, int height, int width, int whic)
{
	if (whic == 0)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->collectable, width * UNIT, height * UNIT);
	else if (whic == 1)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->collectable1, width * UNIT, height * UNIT);
	else if (whic == 2)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->collectable2, width * UNIT, height * UNIT);
	else if (whic == 3)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->collectable3, width * UNIT, height * UNIT);
	else
		whic = 0;
	whic++;
	return (whic);
}

void	show_exit(t_game *data, int width, int height)
{
	data->exit_loc_all_control = data->exit_location_x + data->exit_location_y;
	if (data->exit_loc_all_control == width + height)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer, data->exit,
			width * UNIT, height * UNIT);
}
