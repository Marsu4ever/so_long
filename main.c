/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:07:08 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/21 14:46:38 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*mlx_functions(t_game *game)
{
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game -> mlx);
	free_images(game);
	mlx_terminate(game->mlx);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	char		**map;

	game = NULL;
	map = NULL;
	map = make_and_check_map(map, argv, argc);
	game = initialize_game(game, map);
	game = mlx_functions(game);
	free_map_and_structs(game);
	return (0);
}
