# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:01:02 by mflury            #+#    #+#              #
#    Updated: 2023/03/17 15:01:54 by mflury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra -W

SRC = so_long.c \


all : $(NAME)

$(NAME) : $(OBJ)
	@echo Creating mlx library
	@make -C mlx/
	$(CC) $(OBJ) -Imlx -W ./mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	@echo Creating objets files $<
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@echo Deleting objets files
	@make clean -C mlx/
	@rm -f $(OBJ)
	
fclean : clean 
	@echo Deleting others files
	@rm -f $(NAME) $(NAME).tar.gz $(NAME).zip

re : fclean all

tar :
	@echo Creating TAR.GZ archive
	@tar -czvf $(NAME).tar.gz $(SRC) libft.h Makefile

zip :
	@echo Creating ZIP archive
	@zip -r $(NAME).zip $(SRC) libft.h Makefile

.PHONY : clean fclean re tar zip
