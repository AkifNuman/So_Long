/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:20:06 by akaltine          #+#    #+#             */
/*   Updated: 2023/12/12 11:29:37 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_location_total(t_game *data)
{
	data->exit_location_x = data->index.i;
	data->exit_location_y = data->index.j;
}

void	map_bug2(t_game *data)
{
	if (data->map[data->index.i][data->index.j] == 'C')
		data->control++;
	else if (data->map[data->index.i][data->index.j] != '1'
		&& data->map[data->index.i][data->index.j] != '0'
		&& data->map[data->index.i][data->index.j] != '\n')
		error_message("Unknown value on the map!");
}
