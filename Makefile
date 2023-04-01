# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 07:56:09 by ebennix           #+#    #+#              #
#    Updated: 2023/03/31 03:49:34 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := so_long

CC := cc

CFLAGS := -g -Wall -Wextra -Werror -Imlx

HEADER := so_long.h

FILES := Mandatory/so_long 																									\
		 utils/lib/ft_atoi			utils/lib/ft_lstadd_back	utils/lib/ft_lstadd_front	utils/lib/ft_lstcreate_back		\
		 utils/lib/ft_lstlast		utils/lib/ft_lstnew			utils/lib/ft_lstsize		utils/lib/ft_lstcreate_front	\
		 utils/lib/ft_split			utils/lib/ft_strdup			utils/lib/ft_strjoin		utils/lib/ft_lstfree			\
		 utils/lib/ft_strlen		utils/lib/ft_isdigit		utils/lib/ft_strchr											\
		 utils/gnl/get_next_line	utils/solo/error				 														\

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(EXE)

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
