/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_check_map_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:54:52 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/14 15:56:37 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_number_of_arguments(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("You should pass in only ONE argument - ", 2);
		ft_putstr_fd("and that would be the map. ;) ", 2);
		ft_putstr_fd("You have passed ", 2);
		ft_putnbr_fd(argc - 1, 2);
		ft_putstr_fd(" argument(s).\n", 2);
		exit (1);
	}
}

static void	check_directory_of_map_file(char **argv)
{
	if (ft_strncmp(argv[1], "maps/", 5) != 0
		|| ft_strchr(&argv[1][5], '/') != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd("Invalid file path. Try 'maps/<map_file_name>'", 2);
		exit (1);
	}
}

static void	check_name_of_map(char **argv)
{
	size_t	i;

	i = f_strlen(argv[1]);
	if (i < 9)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map name is too short. ", 2);
		ft_putstr_fd("The name should end with \".ber\".\n", 2);
		exit (1);
	}
	i = i - 4;
	if (ft_strncmp(&argv[1][i], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Incorrect map name. ", 2);
		ft_putstr_fd("The name should end with \".ber\".\n", 2);
		exit (1);
	}
}

void	check_map_name_path_and_argument_count(int argc, char **argv)
{
	check_number_of_arguments(argc);
	check_directory_of_map_file(argv);
	check_name_of_map(argv);
}
