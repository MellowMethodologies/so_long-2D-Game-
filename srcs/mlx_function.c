/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:26:26 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/22 00:04:01 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	doer(t_vars *vars)
{
	if (vars->map[vars->i][vars->j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->floor, 50 * vars->j, 50 * vars->i);
	else if (vars->map[vars->i][vars->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->wall, 50 * vars->j, 50 * vars->i);
	else if (vars->map[vars->i][vars->j] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->floor, 50 * vars->j, 50 * vars->i);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->hero, 50 * vars->j, 50 * vars->i);
	}
	else if (vars->map[vars->i][vars->j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->collective, 50 * vars->j, 50 * vars->i);
	else if (vars->map[vars->i][vars->j] == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->exit_closed, 50 * vars->j, 50 * vars->i);
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->hero, 50 * vars->j, 50 * vars->i);
	}
}

void	ft_call(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->window);
	vars->hero = mlx_xpm_file_to_image(vars->mlx,
			"./assets/hero1.xpm", &vars->img, &vars->img);
	vars->floor = mlx_xpm_file_to_image(vars->mlx,
			"./assets/floor.xpm", &vars->img, &vars->img);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"./assets/wall.xpm", &vars->img, &vars->img);
	vars->exit_open = mlx_xpm_file_to_image(vars->mlx,
			"./assets/portal_open.xpm", &vars->img, &vars->img);
	vars->exit_closed = mlx_xpm_file_to_image(vars->mlx,
			"./assets/portal_closed.xpm", &vars->img, &vars->img);
	vars->collective = mlx_xpm_file_to_image(vars->mlx,
			"./assets/collective.xpm", &vars->img, &vars->img);
	if (!(vars->patrols && vars->hero && vars->floor && vars->wall
			&& vars->exit_open && vars->exit_closed && vars->collective))
	{
		ft_putstr_fd("Error!\ncheck the image path or name", 2);
		exit(1);
	}
}

int	leave(t_vars *vars, int key)
{
	(void)vars;
	(void)key;
	exit(0);
}

void	ft_print_moves(t_vars *vars)
{
	ft_putstr_fd("moves   :   ", 1);
	ft_putnbr_fd(vars->move, 1);
	ft_putstr_fd("\n", 1);
}
