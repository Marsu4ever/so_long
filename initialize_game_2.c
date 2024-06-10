/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:29:56 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 07:31:11 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_x_coordinate(char **map, char map_letter)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == map_letter)
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

static int	find_y_coordinate(char **map, char map_letter)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == map_letter)
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

t_game	*initialize_game_struct(t_game *game, char **map)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
	{
		free_map(map);
		ft_putstr_fd("Error\nFailed to malloc game struct.\n", 2);
		exit (1);
	}
	game->map = map;
	game->width = strlen_until_newline_or_null_terminator(map[0]);
	game->height = calc_number_of_rows(map);
	game->bunny_x = find_x_coordinate(map, 'P');
	game->bunny_y = find_y_coordinate(map, 'P');
	game->exit_x = find_x_coordinate(map, 'E');
	game->exit_y = find_y_coordinate(map, 'E');
	game->carrots = count_number_of_chars(map, 'C');
	game->collected_carrots = 0;
	game->steps = 0;
	return (game);
}

t_game	*add_remaining_tiles_to_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_image_onto_map(game, x, y);
			x++;
		}
		y++;
	}
	return (game);
}

t_game	*make_map_grassy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img->grass,
					x * 64, y * 64) == -1)
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("Failed to put image to window. @grassy\n", 2);
				free_map_structs_and_images_and_then_exit(game);
			}
			x++;
		}
		y++;
	}
	return (game);
}
