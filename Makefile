# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/04/20 05:04:09 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := so_long

ARCH := ../utils/utils.a

CC := cc

CFLAGS := -g -Wall -Wextra -Imlx
# -Werror
HEADER := Mandatory/so_long.h

FILES := Mandatory/so_long 			Mandatory/parsing/read_map				 parsing/drawing\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ)
	$(MAKE) -f $(ARCH)
	$(CC) $(OBJ) $(ARCH) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git
