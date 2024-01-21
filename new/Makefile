NAME = so_long
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
CC = cc
FLAGS = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
LIBFT = libft/*.c
LIBFT_DIR = libft/

RM = rm -f

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(SRC) libft/libft.a -o $(NAME)

run: 
	$(CC) $(FLAGS) $(SRC) libft/libft.a -o $(NAME)
#	./$(NAME) "maps/test_maps/42.fdf"
#	./$(NAME) "maps/test_maps/20-60.fdf"
#	./$(NAME) "maps/test_maps/mars.fdf"
	./$(NAME) "maps/test_maps/test.fdf"

lldb: 
	$(CC) $(FLAGS) $(SRC) libft/libft.a  -o $(NAME)
#	./$(NAME) "maps/test_maps/42.fdf"
#	./$(NAME) "maps/test_maps/20-60.fdf"
#	./$(NAME) "maps/test_maps/mars.fdf"
	lldb ./$(NAME) "maps/test_maps/test.fdf"

clean:
	$(RM) -rf $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(RM) -rf *.a
	$(RM) -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re