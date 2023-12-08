/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:16:34 by bkas              #+#    #+#             */
/*   Updated: 2023/12/08 07:51:26 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_game *data, int i, int j)
{
	if (data->map[i][j] == 'E')
	{		
		if (data->collcounter != data->control)
			return 0;
		ft_printf("YOU WIN..!");
		exit_point(data);
	}
	if (data->map[i][j] == 'C')
	{
		data->collcounter++;
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
	ft_printf("Step Count: %d\n", data->counter);
	ft_printf("Left Coins: %d\n", data->collcounter);
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
	ft_printf("Step Count: %d\n", data->counter);
	ft_printf("Left Coins: %d\n", data->collcounter);
	return (1);
}

int	controls_working(int command, t_game *data)
{
	int	works;

	//if (command != 31)
	//	works = afk(data, command);
	if (command == 53)
		exit_point(data);
	if (command == 13)
		works = keyboard_w_s(data, command);
	if (command == 1)
		works = keyboard_w_s(data, command);
	if (command == 0)
		works = keyboard_a_d(data, command);
	if (command == 2)
		works = keyboard_a_d(data, command);
	if (works)
		adding_graphics(data);
	return (1);
}
