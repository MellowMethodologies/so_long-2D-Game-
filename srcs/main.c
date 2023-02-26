/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:57:04 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/21 18:26:56 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check(t_vars *vars)
{
	vars->i = 0;
	while (vars->i <= vars->r_c[1])
	{
		vars->j = 0;
		while (vars->j <= vars->r_c[0])
		{
			if (vars->map[vars->i][vars->j] == 'P')
			{
				vars->pi = vars->i;
				vars->pj = vars->j;
				return (0);
			}
		vars->j++;
		}
	vars->i++;
	}
	return (0);
}

int	check_c(t_vars *vars)
{
	vars->ii = 0;
	vars->c = 0;
	while (vars->ii <= vars->r_c[1])
	{
		vars->jj = 0;
		while (vars->jj <= vars->r_c[0])
		{
			if (vars->map[vars->ii][vars->jj] == 'C')
				vars->c++;
			vars->jj++;
		}
	vars->ii++;
	}
	if (vars->c == 0)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->exit_open, 50 * vars->j, 50 * vars->i);
	else
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->exit_closed, 50 * vars->j, 50 * vars->i);
	return (0);
}

int	render(t_vars *vars)
{
	vars->i = 0;
	while (vars->i <= vars->r_c[1])
	{
		vars->j = 0;
		while (vars->j <= vars->r_c[0])
		{
			check_c(vars);
			doer(vars);
			vars->j++;
		}
	vars->i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		if (ft_strncmp(".ber", av[1] + (ft_strlen(av[1]) - 4), 4) != 0)
		{
			ft_putstr_fd("Error!\ncheck the extension of your map", 2);
			exit(1);
		}
		parser(av[1], &vars);
		vars.mlx = mlx_init();
		vars.window = mlx_new_window(vars.mlx, 50 * vars.r_c[0],
				(1 + vars.r_c[1]) * 50, "My Window");
		ft_check(&vars);
		ft_call(&vars);
		render(&vars);
		mlx_hook(vars.window, 2, 0, key_press, &vars);
		mlx_hook(vars.window, 17, 0, leave, &vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	else
		ft_putstr_fd("This program only accept \
		.ber file as an argument", 2);
}
