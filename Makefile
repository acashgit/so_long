# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acash <acash@student.21-school.r>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 11:20:10 by acash             #+#    #+#              #
#    Updated: 2021/12/10 11:20:11 by acash            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMEB = so_long_bonus
GCC = gcc
CFLAGS = -Wall -Werror -Wextra

MINILIBX = ./minilibx_/libmlx.a

SRCS = so_long.c \
		so_long_utils.c \
		read_map_utils.c \
		map_check.c \
		initever.c \
		ft_split.c \
		ft_split_utils.c \
		chmap.c \
		start_game.c \
		hook.c \
		move.c \
		events.c \
		ft_itoa.c \
		enemy.c \
		opendoor.c \

SRCSB = so_long_bonus.c \
		so_long_utils_bonus.c \
		read_map_utils_bonus.c \
		map_check_bonus.c \
		initever_bonus.c \
		ft_split_bonus.c \
		ft_split_utils_bonus.c \
		chmap_bonus.c \
		start_game_bonus.c \
		hook_bonus.c \
		move_bonus.c \
		events_bonus.c \
		ft_itoa_bonus.c \
		enemy_bonus.c \
		opendoor_bonus.c \
		
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS) so_long.h Makefile
	$(GCC) $(CFLAGS) $(OBJS) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAMEB): $(OBJSB) so_long_bonus.h Makefile
	$(GCC) $(CFLAGS) $(OBJSB) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)

bonus: $(NAMEB)

clean:
	rm -f $(OBJS) $(OBJSB)
fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re bonus