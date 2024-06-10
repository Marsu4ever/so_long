/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_check_map_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:03:04 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/14 15:59:16 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	are_there_collectibles(char **array_of_map_rows, int *bool_flag)
{
	int	collectibles;

	collectibles = count_number_of_chars(array_of_map_rows, 'C');
	if (collectibles == 0)
	{
		if (*bool_flag == true)
			write(2, "Error\n", 6);
		ft_putstr_fd("You have ", 2);
		ft_putnbr_fd(collectibles, 2);
		ft_putstr_fd(" Collectible Icon(s). ", 2);
		ft_putstr_fd("You should have ONE or MORE in your map.\n", 2);
		*bool_flag = false;
	}
}

static void	is_there_a_single_exit(char **array_of_map_rows, int *bool_flag)
{
	int	exit;

	exit = count_number_of_chars(array_of_map_rows, 'E');
	if (exit != 1)
	{
		if (*bool_flag == true)
			write(2, "Error\n", 6);
		ft_putstr_fd("You have ", 2);
		ft_putnbr_fd(exit, 2);
		ft_putstr_fd(" Exit Icon(s). ", 2);
		ft_putstr_fd("You should only have ONE in your map.\n", 2);
		*bool_flag = false;
	}
}

void	number_of_starts_exits_and_collectibles_is_ok(char **map)
{
	int	start;
	int	bool_flag;

	bool_flag = true;
	start = count_number_of_chars(map, 'P');
	if (start != 1)
	{
		if (bool_flag == true)
			write(2, "Error\n", 6);
		ft_putstr_fd("You have ", 2);
		ft_putnbr_fd(start, 2);
		ft_putstr_fd(" Start Icon(s). ", 2);
		ft_putstr_fd("You should only have ONE in your map.\n", 2);
		bool_flag = false;
	}
	is_there_a_single_exit(map, &bool_flag);
	are_there_collectibles(map, &bool_flag);
	if (bool_flag == false)
	{
		free_map(map);
		exit (1);
	}
}

void	is_the_map_a_rectangle(char	**map)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = strlen_until_newline_or_null_terminator(map[i]);
	i++;
	while (map[i])
	{
		len2 = strlen_until_newline_or_null_terminator(map[i]);
		if (len1 != len2)
		{
			ft_putstr_fd("Error\n The map is not a rectangle. ", 2);
			ft_putstr_fd("The lengths of String[0] and String[", 2);
			ft_putnbr_fd(i, 2);
			ft_putstr_fd("] are ", 2);
			ft_putnbr_fd(len1, 2);
			ft_putstr_fd(" and ", 2);
			ft_putnbr_fd(len2, 2);
			ft_putstr_fd(", respectively.\n", 2);
			free_map(map);
			exit (1);
		}
		i++;
	}
}

void	is_map_too_big(char **map, int num_of_rows_in_map)
{
	int	map_width;

	if (num_of_rows_in_map > 20)
	{
		ft_putstr_fd("Error\nThe map has more than 20 rows. ", 2);
		ft_putstr_fd("Try a smaller map. :)\n", 2);
		free_map(map);
		exit (1);
	}
	map_width = strlen_until_newline_or_null_terminator(map[0]);
	if (map_width > 40)
	{
		ft_putstr_fd("Error\nThe map has more than 40 columns. ", 2);
		ft_putstr_fd("Try a smaller map. :)\n", 2);
		free_map(map);
		exit (1);
	}
}
