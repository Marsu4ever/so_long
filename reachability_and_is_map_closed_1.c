/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachability_and_is_map_closed_1.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:49:41 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 06:53:44 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	floodfill_map(char **ff_map, t_point start, t_point size)
{
	if (start.x < 0 || start.y < 0 || start.x >= size.x || start.y >= size.y)
		return ;
	if (ff_map[start.y][start.x] == '1' || ff_map[start.y][start.x] == 'F')
		return ;
	ff_map[start.y][start.x] = 'F';
	floodfill_map(ff_map, (t_point){start.x + 1, start.y}, size);
	floodfill_map(ff_map, (t_point){start.x, start.y + 1}, size);
	floodfill_map(ff_map, (t_point){start.x - 1, start.y}, size);
	floodfill_map(ff_map, (t_point){start.x, start.y - 1}, size);
}

static t_point	find_coordinates_of_starting_position(char **flood_fill_map)
{
	int		i;
	int		j;
	t_point	start_position;

	i = 0;
	j = 0;
	while (flood_fill_map[i])
	{
		j = 0;
		while (flood_fill_map[i][j])
		{
			if (flood_fill_map[i][j] == 'P')
			{
				start_position.x = j;
				start_position.y = i;
				return (start_position);
			}
			j++;
		}
		i++;
	}
	start_position.x = -1;
	start_position.y = -1;
	return (start_position);
}

static char	**duplicate_map(char **map)
{
	int		num_of_rows_in_map;
	int		i;
	char	**new_array;

	num_of_rows_in_map = calc_number_of_rows(map);
	new_array = (char **)malloc((num_of_rows_in_map + 1) * sizeof(char *));
	if (new_array == NULL)
	{
		ft_putstr_fd("Error\n. Failed to malloc floodfill map\n", 2);
		free_map(map);
		exit (1);
	}
	i = 0;
	while (map[i])
	{
		new_array[i] = ft_strdup(map[i]);
		if (new_array[i] == NULL)
		{
			free_map(map);
			free_incomplete_map_and_exit(new_array, i);
		}
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

static t_point	find_dimensions_of_map(char **map)
{
	int		length_of_map;
	int		height_of_map;
	t_point	size;

	length_of_map = strlen_until_newline_or_null_terminator(map[0]);
	height_of_map = calc_number_of_rows(map);
	size.x = length_of_map;
	size.y = height_of_map;
	return (size);
}

void	is_closed_and_c_and_e_are_reachable(char **map)
{
	char	**flood_fill_map;
	t_point	start;
	t_point	map_size;

	flood_fill_map = duplicate_map(map);
	start = find_coordinates_of_starting_position(flood_fill_map);
	map_size = find_dimensions_of_map(flood_fill_map);
	floodfill_map(flood_fill_map, start, map_size);
	if (!is_c_reachable(flood_fill_map))
	{
		free_two_maps_and_exit(map, flood_fill_map);
	}
	if (!is_e_reachable(flood_fill_map))
	{
		free_two_maps_and_exit(map, flood_fill_map);
	}
	if (!is_map_closed(flood_fill_map))
	{
		free_two_maps_and_exit(map, flood_fill_map);
	}
	free_map(flood_fill_map);
}
