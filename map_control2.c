/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:17:32 by akaltine          #+#    #+#             */
/*   Updated: 2023/12/12 14:08:57 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_bug(t_game *data)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	escape_line(data);
	while (++data->index.i < data->map_height)
	{
		data->index.j = -1;
		while (data->map[data->index.i][++data->index.j])
		{
			if (data->map[data->index.i][data->index.j] == 'P')
				p++;
			else if (data->map[data->index.i][data->index.j] == 'E')
			{
				exit_location_total(data);
				e++;
			}
			else
				map_bug2(data);
		}
	}
	if (p != 1 || e != 1 || data->control == 0)
		error_message("Missing or excess entries!");
}

static char	**create_copy_map(t_game *data)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (data->map_height));
	i = 0;
	while (i < data->map_height)
	{
		new_map[i] = ft_strdup(data->map[i]);
		if (new_map[i] == NULL)
			break ;
		i++;
	}
	return (new_map);
}

static void	path_find(char **copy_map, int *data, int y, int x)
{
	if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
		(*data)++;
	if (copy_map[y][x] == 'E')
		copy_map[y][x] = '1';
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'E')
		return ;
	copy_map[y][x] = '1';
	path_find(copy_map, data, y + 1, x);
	path_find(copy_map, data, y - 1, x);
	path_find(copy_map, data, y, x + 1);
	path_find(copy_map, data, y, x - 1);
}

static void	copy_map_free(char **copy_map, t_game *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(copy_map[i]);
		i++;
	}
	free(copy_map);
}

void	placeholder(t_game *data, int y, int x)
{
	char	**copy_map;
	int		collectibles;

	collectibles = 0;
	copy_map = create_copy_map(data);
	path_find(copy_map, &collectibles, y, x);
	if (collectibles != data->control)
	{
		copy_map_free(copy_map, data);
		error_message("Wrong Map..!!");
		exit_point(data);
	}
	copy_map_free(copy_map, data);
	data->control--;
}
