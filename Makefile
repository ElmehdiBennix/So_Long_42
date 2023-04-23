# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/04/23 21:48:15 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXE := so_long

ARCH := utils/utils.a

CC := cc

CFLAGS := -g -Wall -Wextra -Imlx
# -Werror
HEADER := Mandatory/so_long.h

FILES := Mandatory/so_long 			Mandatory/parsing/read_map		Mandatory/graphics/drawing		\
		 Mandatory/hooks/mlx_hooks		Mandatory/graphics/init_images	\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ)
	make -C utils
	$(CC) $(OBJ) $(ARCH) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C utils
	$(RM) $(OBJ)

fclean : clean
	make fclean -C utils
	$(RM) $(EXE)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git
