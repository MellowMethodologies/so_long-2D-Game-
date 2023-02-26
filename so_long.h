/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:31:36 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/21 23:49:37 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# define BUFFER_SIZE 10

typedef struct vars
{
	void	*mlx;
	void	*window;
	void	*patrols;
	void	*hero;
	void	*exit_closed;
	void	*exit_open;
	void	*collective;
	void	*wall;
	void	*floor;
	int		c;
	int		i;
	int		j;
	int		len;
	int		t;
	int		fd;
	int		r_c[2];
	int		*pos1;
	int		*pos;
	char	*s;
	char	**map;
	char	**map_1;
	int		img;
	int		pi;
	int		pj;
	int		ii;
	int		jj;
	int		move;
}	t_vars;

typedef struct collections{
	int	*tab;
	int	*pos;
	int	j;
	int	i;
	int	len;
	int	t;
	int	p;
	int	c;
	int	e;
	int	s;	
}	t_collectives;

char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
size_t	ft_strlen_b(char *str);
char	*ft_strdup_b(char *src);
char	*ft_strjoin_b(char *s1, char *s2);
void	ft_print_moves(t_vars *vars);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		leave(t_vars *vars, int key);
void	p_fill(t_vars *vars);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_count(char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
void	parser(char *par, t_vars *vars);
void	doer(t_vars *vars);
int		key_press(int key, t_vars *vars);
void	ft_call(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
int		render(t_vars *vars);
void	map_check(t_vars *vars);
#endif