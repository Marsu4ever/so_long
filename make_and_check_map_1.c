/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_check_map_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:14:35 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/14 15:58:16 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**make_map(int num_of_rows_in_map, char **argv)
{
	int		fd;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (num_of_rows_in_map + 1));
	if (map == NULL)
		exit (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile didn't open. ", 2);
		ft_putstr_fd("Was it perchance a misspelt file you added there?\n", 2);
		exit (1);
	}
	i = 0;
	while (i < num_of_rows_in_map)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			free_incomplete_map_and_exit(map, i);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

static int	number_of_rows_in_map(char **argv)
{
	int		fd;
	int		num_of_rows_in_map;
	char	*string;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile didn't open. ", 2);
		ft_putstr_fd("Was it perchance a misspelt file you added there?\n", 2);
		exit (1);
	}
	num_of_rows_in_map = 0;
	string = "let's get into the while loop";
	while (string)
	{
		string = get_next_line(fd);
		if (string)
			num_of_rows_in_map++;
		free (string);
	}
	close (fd);
	return (num_of_rows_in_map);
}

static void	check_for_invalid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E'
			&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("Invalid character (", 2);
				ft_putchar_fd(map[i][j], 2);
				ft_putstr_fd(") found in map. ", 2);
				ft_putstr_fd("The only valid characters are ", 2);
				ft_putstr_fd("P, C, E, 1 and 0.\n", 2);
				free(map);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

char	**make_and_check_map(char **map, char **argv, int argc)
{
	int		num_of_rows_in_map;

	check_map_name_path_and_argument_count(argc, argv);
	num_of_rows_in_map = number_of_rows_in_map(argv);
	map = make_map(num_of_rows_in_map, argv);
	check_for_invalid_characters(map);
	number_of_starts_exits_and_collectibles_is_ok(map);
	is_the_map_a_rectangle(map);
	is_map_too_big(map, num_of_rows_in_map);
	is_closed_and_c_and_e_are_reachable(map);
	return (map);
}
