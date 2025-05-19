CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -fsanitize=address -Ilibft -I./MLX42/include/MLX42/
LDFLAGS = -Llibft -lft -L./MLX42/build -ldl -lglfw -pthread -lm
SRCS = srcs/gen_utils.c srcs/main.c srcs/map_creat_utils.c \
       srcs/map_creat.c srcs/map_utils.c srcs/movement.c \
       srcs/parse_map.c srcs/struct_utils.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a MLX42/build/libmlx42.a
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft

MLX42/build/libmlx42.a:
	cmake -B MLX42/build -S MLX42
	$(MAKE) -C MLX42/build

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re