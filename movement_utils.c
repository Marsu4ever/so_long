/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:59:38 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 06:46:28 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	increment_and_print_steps(t_game *game)
{
	game->steps += 1;
	ft_printf("Steps: %d\n", game->steps);
}

void	disable_carrot_instance(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->carrots)
	{
		if (game->bunny_x == (game->img->carrot->instances[i].x) / 64
			&& game->bunny_y == (game->img->carrot->instances[i].y) / 64)
		{
			game->img->carrot->instances[i].enabled = false;
			game->collected_carrots++;
		}
		i++;
	}
}

void	is_game_over(t_game *game)
{
	if (game->exit_x == game->bunny_x && game->exit_y == game->bunny_y)
	{
		if (game->carrots == game->collected_carrots)
		{
			ft_printf("\n-------------CONGRATULATIONS!------------\n");
			ft_printf("Bunny got to eat all those yummy carrots!\n");
			ft_printf("Bunny made it safely home. :)\n\n");
			mlx_close_window(game->mlx);
		}
	}
}
