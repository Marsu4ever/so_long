/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:35:45 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/14 15:58:00 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*put_collectible_and_exit_onto_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->img->carrot,
				x * 64 + 8, y * 64 + 8) == -1)
		{
			ft_putstr_fd("Error\nFailed to put image to window - @C.\n", 2);
			free_map_structs_and_images_and_then_exit(game);
		}
	}
	if (game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->img->exit,
				x * 64, y * 64) == -1)
		{
			ft_putstr_fd("Error\nFailed to put image to window - @E.\n", 2);
			free_map_structs_and_images_and_then_exit(game);
		}
	}
	return (game);
}

t_game	*put_image_onto_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->img->bush,
				x * 64, y * 64) == -1)
		{
			ft_putstr_fd("Error\nFailed to put image to window - @1.\n", 2);
			free_map_structs_and_images_and_then_exit(game);
		}
	}
	if (game->map[y][x] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->img->bunny,
				x * 64, y * 64) == -1)
		{
			ft_putstr_fd("Error\nFailed to put image to window - @P.\n", 2);
			free_map_structs_and_images_and_then_exit(game);
		}
	}
	game = put_collectible_and_exit_onto_map(game, x, y);
	return (game);
}

static t_game	*set_all_images_to_null(t_game	*game)
{
	game->img->bunny = NULL;
	game->img->carrot = NULL;
	game->img->exit = NULL;
	game->img->bush = NULL;
	game->img->grass = NULL;
	return (game);
}

static t_game	*initialize_image_struct(t_game *game)
{
	t_images	*images;

	images = (t_images *)malloc(sizeof(t_images));
	if (images == NULL)
	{
		ft_putstr_fd("Error\nFailed to malloc image-struct.\n", 2);
		mlx_terminate(game->mlx);
		free_map(game->map);
		free(game);
		exit (1);
	}
	game->img = images;
	game = set_all_images_to_null(game);
	game = load_image_to_struct_grass(game);
	game = load_image_to_struct_bush(game);
	game = load_image_to_struct_bunny(game);
	game = load_image_to_struct_carrot(game);
	game = load_image_to_struct_exit(game);
	return (game);
}

t_game	*initialize_game(t_game *game, char **map)
{
	game = initialize_game_struct(game, map);
	game->mlx = mlx_init(game->width * 64, game->height * 64,
			"Feed the Bunny", false);
	if (game->mlx == NULL)
	{
		free_map(map);
		free(game);
		exit(1);
	}
	game = initialize_image_struct(game);
	game = make_map_grassy(game);
	game = add_remaining_tiles_to_map(game);
	return (game);
}
