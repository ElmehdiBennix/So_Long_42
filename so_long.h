/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/09 20:17:33 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 1

typedef struct coordinates
{
	unsigned int		x;
	unsigned int		y;
	struct coordinates	*next;
}						t_list;

typedef struct s_elements
{
	unsigned int 	player;
	t_list			*p_position;
	unsigned int	collectible;
	t_list			*c_position;
	unsigned int	exit;
	t_list			*e_position;
}					t_elements;
typedef struct s_data
{
	char			**map;
	t_elements		map_elemets;
	unsigned int	h;
	unsigned int	w;
	//char **map_e;
	//char **map_c;
}					t_data;

// parsing
char    **read_map(char *map_name);

//so_long funcs
void	failure(int err);
char	*get_next_line(int fd);

//lib funcs
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char delim);
char	**free_2d(char **str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t size);


// linked list funcs
int		ft_lstsize(t_list *lst);
void	ft_lstfree(void *stack);
void	ft_lstadd_back(t_list **lst, t_list	*node);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstcreate_back(t_list **lst, unsigned int x , unsigned int y);
void	ft_lstcreate_front(t_list **lst, unsigned int x , unsigned int y);
t_list	*ft_lstnew(unsigned int x , unsigned int y);
t_list	*ft_lstlast(t_list *lst);

#endif