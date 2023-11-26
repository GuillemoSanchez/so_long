NAME = so_long

# ------- COLORS -------
NC				=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
LRED			=	\033[1;31m
LGREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
LBLUE			=	\033[1;34m
TITLE			=	\033[38;5;33m

BIN = bin
DIR_SRC = src
INCLUDE = -I inc
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc $(CFLAGS) $(INCLUDE)

# <------ MLX ------>
MLX_DIR = mlx
MLX_PATH = $(MLX_DIR)/libmlx.a
MLX_MAKE = Makefile
MFLAGS = -ldl -lmlx -L${MLX_DIR} -framework OpenGL -framework AppKit -lz

# <------ LIBFT ------>
LIBFT_DIR = libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = Makefile
LFLAGS:= -L $(LIBFT_DIR) -lft

SRC = 	main.c \
		ft_setup.c \
		map_validation.c \
		map.c \
		ft_free_memory.c \
		init_values.c \
		window.c \
		utils_img.c

OBJS = $(SRC:%.c=$(BIN)/%.o)

# <------ RULES/TRIGGER ------>
all: $(NAME)

$(NAME) : $(LIBFT_PATH) $(MLX_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) $(MFLAGS)
	@echo "   $(LGREEN) - $(NAME) compiled 🙂 [OK]${NC}\n"

$(BIN)/%.o : $(DIR_SRC)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(MLX_PATH) :
	@make -C $(MLX_DIR)
	@echo "   $(LGREEN) - MINILIBX compiled 🙂 [OK]${NC}\n"

$(LIBFT_PATH) :
	@cd $(LIBFT_DIR) && make
	@echo "   $(LGREEN) - LIBFT compiled 🙂 [OK]${NC}\n"

clean:
	@make -C $(LIBFT_DIR) -f $(LIBFT_MAKE) fclean
	@make -C $(MLX_DIR) -f $(MLX_MAKE) clean
	rm -rf $(BIN)

fclean: clean
	rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY: all re clean fclean