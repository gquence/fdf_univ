CC = gcc
FLAGS =  -Wextra -Werror -Wall

READ_INC = reading/
READ_SRC = convert_lines.c normalizing.c reading.c strsplit_isspace.c del_all.c
OBJ_READ = $(READ_SRC:.c=.o)
MLX_FLAGS = -I /usr/local/include -L /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit

SRC_DIR = 
INC_DIR = .
SRCS = draw_line.c main.c fdf.c rotation.c rot_matr.c taps.c
OBJ = $(SRCS:.c=.o)

LIB_INC = libft/includes
LIB_DIR = libft/
LIB_NAME = libft.a

NAME = fdf


all: $(LIB_NAME) $(NAME) 

$(LIB_NAME):
	make -C $(LIB_DIR) $(LIB_NAME)

$(NAME): $(LIB_NAME)
	$(CC) -c $(SRC_DIR)$(SRCS) $(addprefix $(READ_INC), $(READ_SRC)) -I $(INC_DIR) -I $(LIB_INC) $(FLAGS)
	$(CC) $(OBJ) $(OBJ_READ) -o $(NAME) -L $(LIB_DIR) -lft -g $(MLX_FLAGS)

clean:
	rm -rf $(OBJ) $(OBJ_READ)
	make -C $(LIB_DIR) clean
	
fclean:
	$(clean) rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
