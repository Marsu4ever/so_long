/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:49:26 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/14 15:57:14 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_images
{
	mlx_image_t		*bunny;
	mlx_image_t		*carrot;
	mlx_image_t		*exit;
	mlx_image_t		*bush;
	mlx_image_t		*grass;
}	t_images;

typedef struct s_game
{
	char			**map;
	int				width;
	int				height;
	int				bunny_x;
	int				bunny_y;
	int				exit_x;
	int				exit_y;	
	int				carrots;
	int				collected_carrots;
	int				steps;
	t_images		*img;
	mlx_t			*mlx;
}	t_game;

t_game		*add_remaining_tiles_to_map(t_game *game);
int			calc_number_of_rows(char **array_of_map_rows);
void		check_map_name_path_and_argument_count(int argc, char **argv);
int			count_number_of_chars(char **array_of_map_rows, char c);
void		disable_carrot_instance(t_game *game);
void		free_images(t_game *game);
void		free_incomplete_map_and_exit(char **map, int i);
void		free_map(char **array_of_strings);
void		free_map_and_structs(t_game *game);
void		free_map_structs_and_images_and_then_exit(t_game *game);
void		free_two_maps_and_exit(char **map, char **flood_fill_map);
char		**make_and_check_map(char **map, char **argv, int argc);
void		increment_and_print_steps(t_game *game);
t_game		*initialize_game(t_game *game, char **map);
t_game		*initialize_game_struct(t_game *game, char **map);
void		is_closed_and_c_and_e_are_reachable(char **array_of_map_rows);
bool		is_c_reachable(char **flood_fill_map);
bool		is_e_reachable(char **flood_fill_map);
void		is_game_over(t_game *game);
bool		is_map_closed(char **flood_fill_map);
void		is_map_too_big(char **map, int num_of_rows_in_map);
void		is_the_map_a_rectangle(char	**map);
t_game		*load_image_to_struct_bunny(t_game *game);
t_game		*load_image_to_struct_bush(t_game *game);
t_game		*load_image_to_struct_carrot(t_game *game);
t_game		*load_image_to_struct_exit(t_game *game);
t_game		*load_image_to_struct_grass(t_game *game);
t_game		*make_map_grassy(t_game *game);
void		move_hook(mlx_key_data_t keydata, void *game_from_key_hook);
void		number_of_starts_exits_and_collectibles_is_ok(char **map);
t_game		*put_image_onto_map(t_game *game, int x, int y);
int			strlen_until_newline_or_null_terminator(const char *s);

#endif