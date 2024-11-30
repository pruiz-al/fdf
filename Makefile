NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX42FLAGS = -Iinclude -ldl -lglfw -pthread -lm
REMOVE = rm -rf

LIBFT_PATH = ./libft/
LIBFT_BIN = $(LIBFT_PATH)libft.a

MLX42_PATH = ./MLX42/build/
MLX42_BIN = $(MLX42_PATH)libmlx42.a

HEADERS	= -I$(LIBFT_PATH) -I./get_next_line -I./inc

SRC = src/draw.c src/fdf.c src/initialization.c\
		src/isometric.c src/parse_fdf.c src/color.c src/free.c\

OBJ = $(SRC:src/%.c=obj/%.o)

BLUE = \033[1;38;5;153m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(LIBFT_BIN) $(NAME)

.SILENT: all $(LIBFT_BIN) $(NAME) $(OBJ) clean fclean re


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_BIN) $(HEADERS) $(MLX42_BIN) $(MLX42FLAGS) -o $@
	echo "\n$(BLUE)$(U_LINE)🥳🎊 $(NAME): Compiled 🥳🎊$(RESET) \n"

$(LIBFT_BIN):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX42) :
	cmake -B MLX42/build -S ./MLX42
	cmake --build MLX42/build -j4

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) $(MLX42FLAGS) -o $@ -c $< $(HEADERS)
	echo "$(YELLOW)FdF Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) obj
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_BIN)
