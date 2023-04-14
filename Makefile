# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:01:02 by mflury            #+#    #+#              #
#    Updated: 2023/03/29 15:13:05 by mflury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra -W -g3 -fsanitize=address

SRC = so_long.c \
		player_move.c \
		mapping.c \



all : $(NAME)

$(NAME) : $(OBJ)
	@echo Creating mlx library
	@make -C mlx/
	@make -C gnl/
	@make -C libft/
	$(CC) $(OBJ) $(CFLAGS) -Imlx ./mlx/libmlx.a -framework OpenGL -framework AppKit ./gnl/get_next_line.a ./libft/libft.a -o $(NAME)

%.o : %.c
	@echo Creating objets files $<
	$(CC) $(CFLAGS) -Imlx -Ignl -Ilibft -c $< -o $@

clean :
	@echo Deleting objets files
	@make clean -C mlx/
	@make clean -C gnl/
	@make clean -C libft/
	@rm -f $(OBJ)
	
fclean : clean 
	@echo Deleting others files
	@rm -f $(NAME) $(NAME).tar.gz $(NAME).zip

re : fclean all

tar :
	@echo Creating TAR.GZ archive
	@tar -czvf $(NAME).tar.gz $(SRC) so_long.h Makefile

zip :
	@echo Creating ZIP archive
	@zip -r $(NAME).zip $(SRC) so_long.h Makefile

.PHONY : clean fclean re tar zip
