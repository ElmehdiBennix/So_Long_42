# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/05/10 04:53:54 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := so_long

EXE_B := so_long_bonus

ARCH := utils/utils.a

CC := cc

CFLAGS := -g -Wall -Wextra -Imlx
# -Werror
HEADER := Mandatory/so_long.h

HEADER := Bonus/so_long.h

FILES := Mandatory/so_long 			Mandatory/parsing/read_map		Mandatory/graphics/drawing		\
		 Mandatory/hooks/mlx_hooks		Mandatory/graphics/init_images	Mandatory/graphics/init_window	\
		 Mandatory/sl_utils/check_utils		Mandatory/sl_utils/draw_utils		Mandatory/parsing/flow_field \

FILES_B := Bonus/so_long 			Bonus/parsing/read_map		Bonus/graphics/drawing		\
		   Bonus/hooks/mlx_hooks	Bonus/graphics/init_window  Bonus/graphics/init_images_2 	Bonus/graphics/init_images_1	 Bonus/graphics/sprites  \
		   Bonus/sl_utils/check_utils		Bonus/sl_utils/draw_utils		Bonus/parsing/flow_field \

SRC := $(FILES:=.c)

OBJ := $(SRC:.c=.o)

SRC_B := $(FILES_B:=.c)

OBJ_B := $(SRC_B:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(EXE)

bonus : $(EXE_B)

library:
	make -C utils

$(EXE) : $(OBJ)
	$(CC) $(OBJ) $(ARCH) -lmlx -framework OpenGL -framework AppKit -o $(EXE)

$(EXE_B) : $(OBJ_B)
	$(CC) $(OBJ_B) $(ARCH) -lmlx -framework OpenGL -framework AppKit -o $(EXE_B)

%.o : %.c $(HEADER) $(HEADER_B) | library
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C utils
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)

fclean : clean
	make fclean -C utils
	$(RM) $(EXE)
	$(RM) $(EXE_B)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

play Bonus:
	./so_long_bonus maps/Mandatory_maps/level1.ber
	./so_long_bonus maps/Mandatory_maps/level2.ber
	./so_long_bonus maps/Mandatory_maps/level3.ber
	./so_long_bonus maps/Mandatory_maps/level4.ber
	./so_long_bonus maps/Mandatory_maps/level5.ber
	./so_long_bonus maps/Mandatory_maps/level6.ber

.PHONY : all clean fclean re git
