/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:11:29 by bkas              #+#    #+#             */
/*   Updated: 2023/12/21 11:40:05 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (data->collectable)
		mlx_destroy_image(data->mlxpointer, data->collectable);
	if (data->exit)
		mlx_destroy_image(data->mlxpointer, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlxpointer, data->wall);
	data->player = NULL;
}

int	exit_location(char *maplocation)
{
	free(maplocation);
	ft_printf("Map not found!");
	exit(1);
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
