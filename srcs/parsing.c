/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:37:29 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/21 18:26:46 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ayy(char **str, t_collectives *col)
{
	col->i = 0;
	col->t = 0;
	col->len = ft_strlen(str[0]);
	col->p = 0;
	col->c = 0;
	col->e = 0;
	col->s = 0;
}

void	all_in(char **str, int c, t_collectives *col)
{
	ayy(str, col);
	while (col->i <= c)
	{
		col->j = 0;
		while (col->j < col->len)
		{
			if (str[col->i][col->j] == 'P')
				col->p += 1;
			else if (str[col->i][col->j] == 'C')
				col->c += 1;
			else if (str[col->i][col->j] == 'E')
				col->e += 1;
			else if (str[col->i][col->j] != '0' && str[col->i][col->j] != '1')
				col->t += 1;
			col->j++;
		}
		col->i++;
	}
	if (col->p != 1 || col->e != 1 || col->c == 0 || col->t != 0)
	{
		ft_putstr_fd("Error!\nchars invalid remember : 1P \
			1E and 1 or more collectives\n", 2);
		exit(1);
	}
}

void	map_check(t_vars *vars)
{
	vars->i = 0;
	while (vars->i <= vars->r_c[1])
	{
		if (ft_strlen(vars->map[vars->i]) != vars->r_c[0])
		{
			ft_putstr_fd("Error!\nmap not squared\n", 2);
			exit(1);
		}
		vars->j = 0;
		while (vars->j < vars->r_c[0])
		{
			if (vars->map[vars->i][0] != '1' || vars->map[0][vars->j] != '1'
				|| vars->map[vars->i][vars->r_c[0] - 1] != '1'
				|| vars->map[vars->r_c[1]][vars->j] != '1')
			{
				ft_putstr_fd("Error!\nmap not surrounded by walls\n", 2);
				exit(1);
			}
			vars->j++;
		}
		vars->i++;
	}
}

void	parser(char *par, t_vars *vars)
{
	t_collectives	col;

	vars->fd = open(par, O_RDONLY);
	if (vars->fd < 0)
	{
		ft_putstr_fd("Error!\ncan't open file", 2);
		exit(1);
	}
	vars->s = get_next_line(vars->fd);
	if (vars->s[0] != '1')
	{
		ft_putstr_fd("Error!\ncheck first line\n", 2);
		exit(1);
	}
	vars->map = ft_split(vars->s, '\n');
	vars->t = ft_count(vars->s, '\n') - 1;
	vars->map_1 = ft_split(vars->s, '\n');
	vars->r_c[0] = ft_strlen(vars->map[0]);
	vars->r_c[1] = vars->t;
	map_check(vars);
	all_in(vars->map, vars->t, &col);
	p_fill(vars);
}
