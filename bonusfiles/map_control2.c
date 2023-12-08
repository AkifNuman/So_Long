/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:21:18 by bkas              #+#    #+#             */
/*   Updated: 2023/09/21 11:46:46 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_bug(t_game *data)
{
	escape_line(data);
	while (++data->index.i < data->map_height)
	{
		data->index.j = -1;
		while (data->map[data->index.i][++data->index.j])
		{
			if (data->map[data->index.i][data->index.j] == 'P')
				data->index.p++;
			else if (data->map[data->index.i][data->index.j] == 'E')
				data->index.e++;
			else if (data->map[data->index.i][data->index.j] == 'N')
				data->index.n++;
			else if (data->map[data->index.i][data->index.j] == 'C')
				data->collectables++;
			else if (data->map[data->index.i][data->index.j] != '1'
				&& data->map[data->index.i][data->index.j] != '0'
				&& data->map[data->index.i][data->index.j] != '\n')
				error_message("Invalid Values in the map..!");
		}
	}
	if (data->index.p != 1 || data->index.e != 1
		|| data->index.n != 1 || data->collectables == 0)
		error_message("Invalid P, E or Collectables");
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
	path_find(copy_map, data, y, x + 1);
	path_find(copy_map, data, y + 1, x);
	path_find(copy_map, data, y, x - 1);
	path_find(copy_map, data, y - 1, x);
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
	if (collectibles != data->collectables + 1)
	{
		copy_map_free(copy_map, data);
		error_message("Wrong Map..!!");
		exit_point(data);
	}
	copy_map_free(copy_map, data);
}