/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:48:55 by bkas              #+#    #+#             */
/*   Updated: 2023/12/08 07:29:32 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc == 2)
	{
		map_control(argv[1], &data);
		map_reading(&data);
		map_processing(&data);
		wall_control(&data);
		data.mlxpointer = mlx_init();
		data.winpointer = mlx_new_window(data.mlxpointer,
				(data.map_width * UNIT), (data.map_height * UNIT), "so_long");
		images_in_game(&data);
		data.player = data.playerright;
		//data.colltot = 0;
		map_bug(&data);
		adding_graphics(&data);
		placeholder(&data, data.player_y, data.player_x);
		mlx_hook(data.winpointer, 17, 0, (void *)exit, 0);
		data.counter = 0;
		mlx_hook(data.winpointer, 2, 0, &controls_working, &data);
		mlx_loop(data.mlxpointer);
	}
	else
		error_message("Error..!\nWrong Argument..!");
	
}