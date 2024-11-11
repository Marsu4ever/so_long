/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:29:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/07/30 12:00:23 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*load_image_to_struct_grass(t_game *game)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./tiles/grass.png");
	if (grass == NULL)
	{
		ft_putstr_fd("Error\nFailed to load grass png.\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	game->img->grass = mlx_texture_to_image(game->mlx, grass);
	if (game->img->grass == NULL)
	{
		ft_putstr_fd("Error\nFailed to convert grass texture to image.\n", 2);
		mlx_delete_texture(grass);
		free_map_structs_and_images_and_then_exit(game);
	}
	mlx_delete_texture(grass);
	if (mlx_resize_image(game->img->grass, 64, 64) == 0)
	{
		ft_putstr_fd("Error\nFailed to resize image (@grass_load).\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	return (game);
}

t_game	*load_image_to_struct_bush(t_game *game)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("./tiles/bush.png");
	if (bush == NULL)
	{
		ft_putstr_fd("Error\nFailed to load bush png.\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	game->img->bush = mlx_texture_to_image(game->mlx, bush);
	if (game->img->bush == NULL)
	{
		ft_putstr_fd("Error\nFailed to convert bush texture to image.\n", 2);
		mlx_delete_texture(bush);
		free_map_structs_and_images_and_then_exit(game);
	}
	mlx_delete_texture(bush);
	if (mlx_resize_image(game->img->bush, 64, 64) == 0)
	{
		ft_putstr_fd("Error\nFailed to resize image (@bush_load).\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	return (game);
}

t_game	*load_image_to_struct_carrot(t_game *game)
{
	mlx_texture_t	*carrot;

	carrot = mlx_load_png("./tiles/carrot.png");
	if (carrot == NULL)
	{
		ft_putstr_fd("Error\nFailed to load carrot png.\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	game->img->carrot = mlx_texture_to_image(game->mlx, carrot);
	if (game->img->carrot == NULL)
	{
		ft_putstr_fd("Error\nFailed to convert carrot texture to image.\n", 2);
		mlx_delete_texture(carrot);
		free_map_structs_and_images_and_then_exit(game);
	}
	mlx_delete_texture(carrot);
	if (mlx_resize_image(game->img->carrot, 50, 50) == 0)
	{
		ft_putstr_fd("Error\nFailed to resize image (@carrot_load).\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	return (game);
}

t_game	*load_image_to_struct_bunny(t_game *game)
{
	mlx_texture_t	*bunny;

	bunny = mlx_load_png("./tiles/bunny.png");
	if (bunny == NULL)
	{
		ft_putstr_fd("Error\nFailed to load bunny png.\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	game->img->bunny = mlx_texture_to_image(game->mlx, bunny);
	if (game->img->bunny == NULL)
	{
		ft_putstr_fd("Error\nFailed to convert bunny texture to image.\n", 2);
		mlx_delete_texture(bunny);
		free_map_structs_and_images_and_then_exit(game);
	}
	mlx_delete_texture(bunny);
	if (mlx_resize_image(game->img->bunny, 64, 64) == 0)
	{
		ft_putstr_fd("Error\nFailed to resize image (@bunny_load).\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	return (game);
}

t_game	*load_image_to_struct_exit(t_game *game)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./tiles/exit.png");
	if (exit == NULL)
	{
		ft_putstr_fd("Error\nFailed to load exit png.\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	game->img->exit = mlx_texture_to_image(game->mlx, exit);
	if (game->img->exit == NULL)
	{
		ft_putstr_fd("Error\nFailed to convert exit texture to image.\n", 2);
		mlx_delete_texture(exit);
		free_map_structs_and_images_and_then_exit(game);
	}
	mlx_delete_texture(exit);
	if (mlx_resize_image(game->img->exit, 64, 64) == 0)
	{
		ft_putstr_fd("Error\nFailed to resize image (@exit_load).\n", 2);
		free_map_structs_and_images_and_then_exit(game);
	}
	return (game);
}
