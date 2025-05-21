CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -fsanitize=address -fsanitize=undefined -Ilibft -I./MLX42/include/MLX42/
LDFLAGS = -Llibft -lft -L./MLX42/build -ldl -lglfw -pthread -lm
BFLAGS = -I /includes/so_long_bonus.h
SRCS = srcs/gen_utils.c srcs/main.c srcs/map_creat_utils.c \
		srcs/map_creat.c srcs/map_utils.c srcs/movement.c \
		srcs/parse_map.c srcs/struct_utils.c srcs/game.c

SRCSB = srcs/gen_utils.c srcs/main.c srcs_bonus/map_creat_utils_bonus.c \
		srcs/map_utils.c srcs/parse_map.c \
		srcs_bonus/struct_utils_bonus.c srcs_bonus/game_bonus.c \
		srcs_bonus/movement_bonus.c srcs_bonus/map_creat_bonus.c \
		srcs_bonus/utils_bonus.c srcs_bonus/game_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a MLX42/build/libmlx42.a
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

libft/libft.a:
	$(MAKE) -C libft

MLX42/build/libmlx42.a:
	cmake -B MLX42/build -S MLX42
	$(MAKE) -C MLX42/build

bonus: $(OBJSB) libft/libft.a MLX42/build/libmlx42.a
		$(CC) $(CFLAGS) $(BFLAGS) $^ $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJSB)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) libft.a
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re