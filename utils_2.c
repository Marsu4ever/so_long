/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:43:51 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 06:49:58 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_number_of_chars(char **array_of_map_rows, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (array_of_map_rows[i] != NULL)
	{
		while (array_of_map_rows[i][j] != '\0')
		{
			if (array_of_map_rows[i][j] == c)
			{
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	free_two_maps_and_exit(char **map, char **flood_fill_map)
{
	free_map(map);
	free_map(flood_fill_map);
	exit (1);
}

void	free_incomplete_map_and_exit(char **map, int i)
{
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Failed to make map.\n", 2);
	exit (1);
}

void	free_map(char **array_of_strings)
{
	int	i;

	i = 0;
	while (array_of_strings[i])
	{
		free(array_of_strings[i]);
		i++;
	}
	free(array_of_strings);
}
