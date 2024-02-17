CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -lft -lmlx -lXext -lX11
LIBFT_DIR = ./libft
NAME = so_long

SRCS = \
	0.0_main.c 1.0_map_read.c 1.1_map_validation.c 1.2_map_flood_fill.c \
	2.0_data_initialization.c 2.1_image_import.c 3.0_map_initialization.c \
	4.0_gameplay.c 4.1_move_player.c 5.0_error_handling_fd.c \
	5.0_error_handling_map.c 5.0_error_handling_mlx.c 5.1_free.c

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L$(LIBFT_DIR) $(LFLAGS)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
