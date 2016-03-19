/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:39:05 by sganon            #+#    #+#             */
/*   Updated: 2016/03/19 14:14:46 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc <= 1 || argc > 5)
		ft_error(0);
	e = (t_env *)malloc(sizeof(t_env));
	if (!(check_argv(argc, argv, e)))
		ft_error(1);
	if (!(init_env(e)))
		return (0);
	handle_fractal(e);
	if (e->ship)
	{
		mlx_key_hook(e->sh->win, ship_key_events, e);
		mlx_mouse_hook(e->sh->win, ship_mouse_events, e);
		mlx_expose_hook(e->sh->win, expose_hook, e);
	}
	mlx_loop(e->mlx);
	ft_putendl("d7\n");
	return (0);
}
