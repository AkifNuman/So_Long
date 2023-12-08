/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:52:56 by bkas              #+#    #+#             */
/*   Updated: 2023/09/19 16:41:46 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_run(t_game *data)
{
	data->enemy_speed++;
	if (data->enemy_speed >= 10)
	{
		data->enemy_speed = 0;
		return (0);
	}
	else
		return (1);
}

int	wall_check(t_game *data)
{
	static int	wallcheck = 0;

	if (data->map[data->ghost_y][data->ghost_x - 1] == '1')
	{
		wallcheck = 0;
		return (wallcheck);
	}
	else if (data->map[data->ghost_y][data->ghost_x + 1] == '1')
	{
		wallcheck = 1;
		return (wallcheck);
	}
	else
		return (wallcheck);
}

int	controls1(t_game *data)
{
	int	wallcheck;

	if (enemy_run(data) == 0)
		data->enemy_speed = 0;
	else
		return (1);
	wallcheck = wall_check(data);
	if (wallcheck != 0)
		controls2(data);
	else if (wallcheck != 1)
		controls3(data);
	return (1);
}

void	controls2(t_game *data)
{
	data->ghost_x--;
	data->ghost = data->ghost_left;
}

void	controls3(t_game *data)
{
	data->ghost_x++;
	data->ghost = data->ghost_right;
}
