/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachability_and_is_map_closed_3.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:25:08 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 07:11:09 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_last_char_index_in_string(char **flood_fill_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flood_fill_map[i][j] != '\0' && flood_fill_map[i][j] != 10)
	{
		j++;
	}
	j--;
	return (j);
}

static int	get_last_row_index_in_array(char **flood_fill_map)
{
	int	i;

	i = 0;
	while (flood_fill_map[i])
	{
		i++;
	}
	i--;
	return (i);
}

static bool	no_f_letter_on_horizontal_edge(char **floodmap, int constant, int i)
{
	int	letter_count;

	letter_count = 0;
	while (floodmap[constant][i])
	{
		if (floodmap[constant][i] == 'F')
		{
			letter_count++;
		}
		i++;
	}
	if (letter_count != 0)
	{
		write(2, "Error\n", 6);
		ft_putstr_fd("You have ", 2);
		ft_putnbr_fd(letter_count, 2);
		ft_putstr_fd(" hole(s) in your horizontal walls. ", 2);
		ft_putstr_fd("The walls should be closed.\n", 2);
		return (false);
	}
	return (true);
}

static bool	no_f_letter_on_vertical_edge(char **flood_map, int i, int constant)
{
	int	letter_count;

	letter_count = 0;
	while (flood_map[i])
	{
		if (flood_map[i][constant] == 'F')
		{
			letter_count++;
		}
		i++;
	}
	if (letter_count != 0)
	{
		write(2, "Error\n", 6);
		ft_putstr_fd("You have ", 2);
		ft_putnbr_fd(letter_count, 2);
		ft_putstr_fd(" hole(s) in your vertical walls. ", 2);
		ft_putstr_fd("The walls should be closed.\n", 2);
		return (false);
	}
	return (true);
}

bool	is_map_closed(char **flood_fill_map)
{
	int	max_h_index;
	int	max_v_index;
	int	i;

	max_h_index = get_last_char_index_in_string(flood_fill_map);
	max_v_index = get_last_row_index_in_array(flood_fill_map);
	i = 0;
	if (!no_f_letter_on_horizontal_edge(flood_fill_map, 0, i))
		return (false);
	if (!no_f_letter_on_horizontal_edge(flood_fill_map, max_v_index, i))
		return (false);
	if (!no_f_letter_on_vertical_edge(flood_fill_map, i, 0))
		return (false);
	if (!no_f_letter_on_vertical_edge(flood_fill_map, i, max_h_index))
		return (false);
	return (true);
}
