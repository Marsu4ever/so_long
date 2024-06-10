/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:44:36 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 08:55:01 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	int		x;
	int		y;
	t_point	start_point;

	x = game->bunny_x;
	y = game->bunny_y;
	start_point.x = x;
	start_point.y = y;
	y = y - 1;
	if (y >= 0 && y < game->height && game->map[y][x] != '1')
	{
		game->bunny_y = game->bunny_y - 1;
		if (game->map[game->bunny_y][game->bunny_x] == 'C')
			disable_carrot_instance(game);
		game->map[start_point.y][start_point.x] = '0';
		if (game->exit_x == start_point.x && game->exit_y == start_point.y)
		{
			game->map[start_point.y][start_point.x] = 'E';
		}
		game->map[y][x] = 'P';
		game->img->bunny->instances[0].y -= 1 * 64;
		increment_and_print_steps(game);
		is_game_over(game);
	}
}

static void	move_down(t_game *game)
{
	int		x;
	int		y;
	t_point	start_point;

	x = game->bunny_x;
	y = game->bunny_y;
	start_point.x = x;
	start_point.y = y;
	y = y + 1;
	if (y >= 0 && y < game->height && game->map[y][x] != '1')
	{
		game->bunny_y = game->bunny_y + 1;
		if (game->map[game->bunny_y][game->bunny_x] == 'C')
			disable_carrot_instance(game);
		game->map[start_point.y][start_point.x] = '0';
		if (game->exit_x == start_point.x && game->exit_y == start_point.y)
		{
			game->map[start_point.y][start_point.x] = 'E';
		}
		game->map[y][x] = 'P';
		game->img->bunny->instances[0].y += 1 * 64;
		increment_and_print_steps(game);
		is_game_over(game);
	}
}

static void	move_right(t_game *game)
{
	int		x;
	int		y;
	t_point	start_point;

	x = game->bunny_x;
	y = game->bunny_y;
	start_point.x = x;
	start_point.y = y;
	x = x + 1;
	if (x >= 0 && x < game->width && game->map[y][x] != '1')
	{
		game->bunny_x = game->bunny_x + 1;
		if (game->map[game->bunny_y][game->bunny_x] == 'C')
			disable_carrot_instance(game);
		game->map[start_point.y][start_point.x] = '0';
		if (game->exit_x == start_point.x && game->exit_y == start_point.y)
		{
			game->map[start_point.y][start_point.x] = 'E';
		}
		game->map[y][x] = 'P';
		game->img->bunny->instances[0].x += 1 * 64;
		increment_and_print_steps(game);
		is_game_over(game);
	}
}

static void	move_left(t_game *game)
{
	int		x;
	int		y;
	t_point	start_point;

	x = game->bunny_x;
	y = game->bunny_y;
	start_point.x = x;
	start_point.y = y;
	x = x - 1;
	if (x >= 0 && x < game->width && game->map[y][x] != '1')
	{
		game->bunny_x = game->bunny_x - 1;
		if (game->map[game->bunny_y][game->bunny_x] == 'C')
			disable_carrot_instance(game);
		game->map[start_point.y][start_point.x] = '0';
		if (game->exit_x == start_point.x && game->exit_y == start_point.y)
		{
			game->map[start_point.y][start_point.x] = 'E';
		}
		game->map[y][x] = 'P';
		game->img->bunny->instances[0].x -= 1 * 64;
		increment_and_print_steps(game);
		is_game_over(game);
	}
}

void	move_hook(mlx_key_data_t keydata, void *game_from_key_hook)
{
	t_game	*game;

	game = (t_game *) game_from_key_hook;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
}
