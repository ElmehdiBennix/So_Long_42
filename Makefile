# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/04/13 10:57:55 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := so_long

CC := cc

CFLAGS := -g -Wall -Wextra -Imlx
# -Werror
HEADER := so_long.h

FILES := Mandatory/so_long 			parsing/read_map													\
		 utils/lib/ft_atoi					\
		 parsing/drawing	\
		 utils/lib/ft_split			utils/lib/ft_strdup			utils/lib/ft_strjoin				\
		 utils/lib/ft_strlen		utils/lib/ft_isdigit		utils/lib/ft_strchr			utils/lib/ft_strncmp			\
		 utils/lib/ft_strnstr		utils/gnl/get_next_line		utils/solo/error			utils/lib/ft_bzero	 utils/lib/ft_calloc	\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(EXE)

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
