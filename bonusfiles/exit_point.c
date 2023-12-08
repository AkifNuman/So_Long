/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:47:27 by bkas              #+#    #+#             */
/*   Updated: 2023/09/21 11:54:03 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_images_free(t_game *data)
{
	if (data->playerup)
		mlx_destroy_image(data->mlxpointer, data->playerup);
	if (data->playerdown)
		mlx_destroy_image(data->mlxpointer, data->playerdown);
	if (data->playerleft)
		mlx_destroy_image(data->mlxpointer, data->playerleft);
	if (data->playerright)
		mlx_destroy_image(data->mlxpointer, data->playerright);
	if (data->ghost_right)
		mlx_destroy_image(data->mlxpointer, data->ghost_right);
	if (data->ghost_left)
		mlx_destroy_image(data->mlxpointer, data->ghost_left);
	if (data->close)
		mlx_destroy_image(data->mlxpointer, data->close);
	if (data->collectable)
		mlx_destroy_image(data->mlxpointer, data->collectable);
	if (data->exit)
		mlx_destroy_image(data->mlxpointer, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlxpointer, data->wall);
	data->player = NULL;
	data->ghost = NULL;
}

int	exit_point(t_game *data)
{
	int	line;

	line = 0;
	if (data->winpointer)
		mlx_destroy_window(data->mlxpointer, data->winpointer);
	while (line < data->map_height)
		free(data->map[line++]);
	free(data->map);
	free(data->maplocation);
	mlx_images_free(data);
	exit(0);
}
