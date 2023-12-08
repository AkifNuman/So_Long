/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:06:07 by bkas              #+#    #+#             */
/*   Updated: 2023/09/19 16:29:21 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	right_move(t_game *data, int i, int j)
{
	if (data->map[i][j] == 'E')
	{
		if (data->collectables != 0)
			return (0);
		ft_printf("YOU WIN..!");
		exit_point(data);
	}
	if (data->map[i][j] == 'C')
	{
		data->collectables--;
	}
	if (data->map[i][j] == 'N')
	{
		ft_printf("YOU LOSE..!");
		exit_point(data);
	}
	data->map[i][j] = 'P';
	data->player_x = j;
	data->player_y = i;
	data->counter++;
	return (1);
}

static int	keyboard_w_s(t_game *data, int movement)
{
	data->index.j = data->player_x;
	data->index.i = data->player_y;
	if (movement == 13)
	{
		if (data->map[--data->index.i][data->index.j] == '1')
			return (0);
		data->index.k = right_move(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i + 1][data->index.j] = '0';
		data->player = data->playerup;
	}
	else if (movement == 1)
	{
		if (data->map[++data->index.i][data->index.j] == '1')
			return (0);
		data->index.k = right_move(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i - 1][data->index.j] = '0';
		data->player = data->playerdown;
	}
	return (1);
}

static int	keyboard_a_d(t_game *data, int movement)
{
	data->index.j = data->player_x;
	data->index.i = data->player_y;
	if (movement == 0)
	{
		if (data->map[data->index.i][--data->index.j] == '1')
			return (0);
		data->index.k = right_move(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i][data->index.j + 1] = '0';
		data->player = data->playerleft;
	}
	else if (movement == 2)
	{
		if (data->map[data->index.i][++data->index.j] == '1')
			return (0);
		data->index.k = right_move(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i][data->index.j - 1] = '0';
		data->player = data->playerright;
	}
	return (1);
}

int	controls_working(int command, t_game *data)
{
	if (command == 53)
		exit_point(data);
	if (command == 13)
		keyboard_w_s(data, command);
	if (command == 1)
		keyboard_w_s(data, command);
	if (command == 0)
		keyboard_a_d(data, command);
	if (command == 2)
		keyboard_a_d(data, command);
	return (1);
}
