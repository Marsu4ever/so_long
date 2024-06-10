/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:43:22 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/21 14:50:06 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->img->bunny != NULL)
	{
		mlx_delete_image(game->mlx, game->img->bunny);
		// free(game->img->bunny);
	}
	if (game->img->carrot != NULL)
	{
		mlx_delete_image(game->mlx, game->img->carrot);
	}
	if (game->img->exit != NULL)
	{
		mlx_delete_image(game->mlx, game->img->exit);
	}
	if (game->img->bush != NULL)
	{
		mlx_delete_image(game->mlx, game->img->bush);
	}
	if (game->img->grass != NULL)
	{
		mlx_delete_image(game->mlx, game->img->grass);
	}
}

void	free_map_structs_and_images_and_then_exit(t_game *game)
{
	free_images(game);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->img);
	free(game);
	exit (1);
}

void	free_map_and_structs(t_game *game)
{
	free_map(game->map);
	free(game->img);
	free(game);
}
