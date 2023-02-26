/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:16:39 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/22 00:18:04 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->pi - 1][vars->pj] == '0'
	|| vars->map[vars->pi - 1][vars->pj] == 'C')
	{
		vars->map[vars->pi - 1][vars->pj] = 'P';
		vars->map[vars->pi][vars->pj] = '0';
		vars->move += 1;
		ft_print_moves(vars);
		vars->pi -= 1;
	}
	else if (vars->map[vars->pi - 1][vars->pj] == 'E' && !vars->c)
	{
		ft_putstr_fd("moves   :   ", 1);
		ft_putnbr_fd(vars->move + 1, 1);
		ft_putstr_fd("\nyou Won!", 1);
		exit(0);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->pi + 1][vars->pj] == '0'
	|| vars->map[vars->pi + 1][vars->pj] == 'C')
	{
		vars->map[vars->pi][vars->pj] = '0';
		vars->map[vars->pi + 1][vars->pj] = 'P';
		vars->move += 1;
		ft_print_moves(vars);
		vars->pi += 1;
	}
	else if (vars->map[vars->pi + 1][vars->pj] == 'E' && !vars->c)
	{
		ft_putstr_fd("moves   :   ", 1);
		ft_putnbr_fd(vars->move + 1, 1);
		ft_putstr_fd("\nyou Won!", 1);
		exit(0);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->pi][vars->pj - 1] == '0'
	|| vars->map[vars->pi][vars->pj - 1] == 'C')
	{
		vars->map[vars->pi][vars->pj] = '0';
		vars->map[vars->pi][vars->pj - 1] = 'P';
		vars->move += 1;
		ft_print_moves(vars);
		vars->pj -= 1;
	}
	else if (vars->map[vars->pi][vars->pj - 1] == 'E' && !vars->c)
	{
		ft_putstr_fd("moves   :   ", 1);
		ft_putnbr_fd(vars->move + 1, 1);
		ft_putstr_fd("\nyou Won!", 1);
		exit(0);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->pi][vars->pj + 1] == '0'
	|| vars->map[vars->pi][vars->pj + 1] == 'C')
	{
		vars->map[vars->pi][vars->pj] = '0';
		vars->map[vars->pi][vars->pj + 1] = 'P';
		vars->move += 1;
		ft_print_moves(vars);
		vars->pj += 1;
	}
	else if (vars->map[vars->pi][vars->pj + 1] == 'E' && !vars->c)
	{
		ft_putstr_fd("moves   :   ", 1);
		ft_putnbr_fd(vars->move + 1, 1);
		ft_putstr_fd("\nyou Won!", 1);
		exit(0);
	}
}

int	key_press(int key, t_vars *vars)
{
	if (key == 0 || key == 123)
		move_left(vars);
	else if (key == 2 || key == 124)
		move_right(vars);
	else if (key == 1 || key == 125)
		move_down(vars);
	else if (key == 13 || key == 126)
		move_up(vars);
	else if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
	render(vars);
	return (0);
}
