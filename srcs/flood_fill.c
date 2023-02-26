/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:36 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/21 23:49:46 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_0c(t_vars *vars)
{
	vars->i = 0;
	while (vars->i < vars->r_c[1])
	{
		vars->j = 0;
		while (vars->j <= vars->r_c[0])
		{
			if ((vars->map_1[vars->i][vars->j] == '0'
				|| vars->map_1[vars->i][vars->j] == 'C')
				&& (vars->map_1[vars->i + 1][vars->j] == 'P'
				|| vars->map_1[vars->i - 1][vars->j] == 'P'
				|| vars->map_1[vars->i][vars->j - 1] == 'P'
				|| vars->map_1[vars->i][vars->j + 1] == 'P'))
				return (1);
			vars->j++;
		}
		vars->i++;
	}
	return (0);
}

int	exit_valid(t_vars *vars)
{
	vars->i = 0;
	while (vars->i < vars->r_c[1])
	{
		vars->j = 0;
		while (vars->j <= vars->r_c[0])
		{
			if (vars->map_1[vars->i][vars->j] == 'E'
				&& (vars->map_1[vars->i + 1][vars->j] != 'P'
				&& vars->map_1[vars->i - 1][vars->j] != 'P'
				&& vars->map_1[vars->i][vars->j - 1] != 'P'
				&& vars->map_1[vars->i][vars->j + 1] != 'P'))
			{
				ft_putstr_fd("Error!\n----map not winnable! retry", 2);
				exit(1);
			}
			vars->j++;
		}
		vars->i++;
	}
	return (0);
}

void	full_check(t_vars *vars)
{
	vars->i = 0;
	while (vars->i < vars->r_c[1])
	{
		vars->j = 0;
		while (vars->j <= vars->r_c[0])
		{
			if (vars->map_1[vars->i][vars->j] == 'C')
			{
				ft_putstr_fd("Error!\n----map not winnable! retry", 2);
				exit(1);
			}
			vars->j++;
		}
		vars->i++;
	}
	exit_valid(vars);
}

static void	*ft_freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	p_fill(t_vars *vars)
{
	while (check_0c(vars))
		vars->map_1[vars->i][vars->j] = 'P';
	full_check(vars);
	ft_freeall(vars-> map_1);
}
