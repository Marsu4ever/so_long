NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

LIBS = 	$(LIBFT)\
		$(MLX_LIB)\
		-lglfw\
		-ldl\
		-pthread\

LINK_DIR = -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SOURCES = 	initialize_game_1.c\
			initialize_game_2.c\
			initialize_game_3.c\
			main.c\
			make_and_check_map_utils.c\
			make_and_check_map_1.c\
			make_and_check_map_2.c\
			make_and_check_map_3.c\
			movement_utils.c\
			movement.c\
			reachability_and_is_map_closed_1.c\
			reachability_and_is_map_closed_2.c\
			reachability_and_is_map_closed_3.c\
			utils_1.c\
			utils_2.c\

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(MLX_LIB)
	cc $(CFLAGS) $(OBJECTS) $(LINK_DIR) $(LIBS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4;

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT_DIR)
#	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX_LIB)

re: fclean all

.PHONY: all, clean, fclean, re