NAME = so_long
NAME_BONUS = so_long_bonus

HDR = src/so_long.h
HDR_BONUS = src_bonus/so_long_bonus.h

SRC = map/read_file.c main.c free.c \
map/check_map.c map/map.c map/valid_file.c \
start.c put_image.c move.c\
data.c
SRC_BONUS = map/read_file_bonus.c main_bonus.c free_bonus.c \
map/check_map_bonus.c map/map_bonus.c map/valid_file_bonus.c \
start_bonus.c put_image_bonus.c water_border_bonus.c \
data_bonus.c animation_bonus.c init_image_bonus.c \
water_inside_bonus.c put_mob_bonus.c \
move_perso_bonus.c move_ennemy_bonus.c

OBJS = ${addprefix src/,${SRC:.c=.o}}
OBJS_BONUS = ${addprefix src_bonus/,${SRC_BONUS:.c=.o}}

LIBMLX = mlx_linux

LIBFT_AR = libft/libft.a 
MLX_AR= ${LIBMLX}/libmlx.a

INCLUDE_LINUX = -Ilibft/ -I/usr/include -Imlx_linux
LES_LIBS_LINUX = -Llibft -lft -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

INCLUDE_MAC = -Ilibft/ -Imlx_mac
LES_LIBS_MAC = -Llibft -lft -Lmlx_mac -lmlx -framework OpenGL -framework AppKit

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

%.o: %.c ${HDR} ${HDR_BONUS} ${LIBFT_AR} ${MLX_AR} Makefile
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE_LINUX}

all: libft mlx_linux ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LES_LIBS_LINUX}

bonus: libft mlx_linux ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${LES_LIBS_LINUX}

libft:
	make -C libft

mlx_linux:
	make -C ${LIBMLX}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	make clean -C ${LIBMLX}
	make clean -C libft

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make fclean -C libft

re: fclean all

.PHONY: all bonus mlx_linux libft clean fclean re
