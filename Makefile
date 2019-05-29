CC = gcc
FLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS_LINUX = -l mlx -L /usr/lib/x86_64-linux-gnu/ -l Xext -l m -l X11
SRC_DIR = 
INC_DIR = -I . -I libft/includes/
SRCS = draw_line.c main.c  reading/*.c libft/libft.a
OBJ = $(SRCS:.c=.o)
NAME = fdf
LIB = make -C libft/ re

all: $(LIB) $(NAME)

allL:
	make -C minilibx -f Makefile.gen all
	$(LIB)
	$(CC) $(SRCS) -o fdf $(FLAGS_LINUX) $(INC_DIR)

$(NAME):
	$(CC) $(SRCS) -o $(NAME) $(FLAGS)
	
clean:
	rm -rf $(NAME)

re: clean all
