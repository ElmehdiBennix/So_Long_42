/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/12 00:00:57 by ebennix          ###   ########.fr       */
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

// if i pass it without allocating the meme needed it will crash better to allocate and end it with null
// if i exited to scope of the fuction which has the variable and its value it will
//be lost so we need to allocate it in the heap 

// typedef struct img_s
// {
// 	void	*img_floor;
// 	void	*img_player;
// 	void	*img_exit;
// 	void	*img_wall;
// 	void	*img_collect;
// 	int		height;
// 	int		width;
// 	char	*player;
// 	char	*floor;
// 	char	*wall;
// 	char	*collect;
// 	char	*exit;
// }				t_img;

typedef struct s_elements
{
	unsigned int 	p_count;
	unsigned int 	c_count;
	unsigned int	e_count;
}				t_elements;

typedef struct s_position
{
	int		x;
	int		y;
}				t_position;

typedef struct s_data
{
	char			**map;
	unsigned int	height;
	unsigned int	width;
	t_elements		elements;
	t_position		p_position;	
}					t_data;

// parsing
char    **read_map(char *map_name, t_data *map);

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

#endif