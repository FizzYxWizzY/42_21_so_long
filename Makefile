# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:01:02 by mflury            #+#    #+#              #
#    Updated: 2023/06/01 16:21:24 by mflury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OBJ = $(SRC:.c=.o)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra -W

SRC = so_long.c \
		map_parsing.c \
		map_checking.c \
		map_checking_utils.c \
		floodfill.c \
		map_building.c \
		player_move.c \
		free_utils.c \
		error.c \
		item_picking.c \


all : $(NAME)

$(NAME) : $(OBJ)
	@echo Creating library
	@make -C printf/
	@make -C gnl/
	@make -C mlx/
	$(CC) $(OBJ) $(CFLAGS) -Imlx ./mlx/libmlx.a -framework OpenGL -framework AppKit ./gnl/get_next_line.a ./printf/libftprintf.a -o $(NAME)

%.o : %.c
	@echo Creating objets files $<
	$(CC) $(CFLAGS) -Iprintf -Ignl -Imlx -c $< -o $@

clean :
	@echo Deleting objets files
	@make clean -C printf/
	@make clean -C gnl/
	@make clean -C mlx/
	@rm -f $(OBJ)
	
fclean : clean 
	@echo Deleting others files
	@make fclean -C printf/
	@make fclean -C gnl/
	@rm -f $(NAME) $(NAME).tar.gz $(NAME).zip

re : fclean all

tar :
	@echo Creating TAR.GZ archive
	@tar -czvf $(NAME).tar.gz $(SRC) so_long.h Makefile

zip :
	@echo Creating ZIP archive
	@zip -r $(NAME).zip $(SRC) so_long.h Makefile

.PHONY : clean fclean re tar zip
