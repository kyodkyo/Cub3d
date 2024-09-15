NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ./mlx clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re