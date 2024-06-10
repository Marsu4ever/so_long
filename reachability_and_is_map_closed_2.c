/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachability_and_is_map_closed_2.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:52:59 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 07:00:56 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_c_reachable(char **flood_fill_map)
{
	int	number_of_collectibles;

	number_of_collectibles = count_number_of_chars(flood_fill_map, 'C');
	if (number_of_collectibles != 0)
	{
		write(2, "Error\n", 6);
		ft_putstr_fd("C is not reachable. You have ", 2);
		ft_putnbr_fd(number_of_collectibles, 2);
		ft_putstr_fd(" unreachable collectible(s) in your map.\n", 2);
		return (false);
	}
	return (true);
}

bool	is_e_reachable(char **flood_fill_map)
{
	int	number_of_exits;

	number_of_exits = count_number_of_chars(flood_fill_map, 'E');
	if (number_of_exits != 0)
	{
		write(2, "Error\n", 6);
		ft_putstr_fd("E is not reachable. You have ", 2);
		ft_putnbr_fd(number_of_exits, 2);
		ft_putstr_fd(" unreachable exit(s) in your map.\n", 2);
		return (false);
	}
	return (true);
}
