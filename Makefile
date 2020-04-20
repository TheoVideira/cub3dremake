CC				= gcc

CFLAGS			= -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS		= -lmlx -framework OpenGL -framework AppKit
MLX_WSL_FLAGS	= -L/usr/local/lib -lmlx -lm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lbsd
LIBRARIES		= libft/libft.a gnl/gnl.a
INCLUDES_FOLDER	= gnl includes libft
INCLUDES		= $(addprefix -I, $(INCLUDES_FOLDER))
INCLUDES_FILES	= libft/libft.h gnl/get_next_line.h includes/cub3D.h

NAME			= cub3D

SRCS_DIR		= srcs
SRCS_FILES		= check.c check_texture.c error.c get_map_utils.c init_struct.c key.c parser.c parser_col.c parser_res.c render.c \
				  check_info.c closed_map_utils.c first_check_map.c get_sprite.c init_texture.c main.c parser_args.c parser_map.c \
				  parser_tex.c render_wall.c render_wall_bis.c render_sprite.c render_sprite_bis.c bmp_save.c
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR		= objs
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARIES) $(INCLUDES_FILES)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES) $(MLX_WSL_FLAGS) -o $(NAME)

mac: $(OBJS) $(LIBRARIES) $(INCLUDES_FILES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)


$(LIBRARIES):
	$(MAKE) -C libft
	$(MAKE) -C gnl

debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJS) $(LIBRARIES) -o $(NAME) $(MLX_WSL_FLAGS)

debug_mac:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(MLX_FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)

#Create .o folder
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

#Compile .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C gnl clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C gnl fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
