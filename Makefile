CC = gcc -g
NAME = madagascar
NAME_B = so_long_bonus
SRC = ./src/so_long.c ./utils/put.c ./src/utils.c \
	  	./src/window_utils.c ./utils/split.c ./src/window_move.c \
		./src/display_image.c ./src/valid_path.c ./src/utils1.c \
		./utils/put2.c ./src/display_player.c ./src/foko.c
OBJ = $(SRC:.c=.o)
LIB_DIR = ./minilibx-linux
LIB = $(LIB_DIR)/libmlx.a $(LIB_DIR)/libmlx_Linux.a

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	${MAKE} -C ./minilibx-linux
	$(CC) $(OBJ) -L$(LIB_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	${MAKE} clean -C ./minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
