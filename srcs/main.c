/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:39:05 by sganon            #+#    #+#             */
/*   Updated: 2016/02/23 14:51:22 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env	*e;
	(void)argc;
	(void)argv;

	e = (t_env *)malloc(sizeof(t_env));
	if (!(init_env(e)))
		return (0);
	mandel(e);
	mlx_key_hook(e->win, key_events, e);
	mlx_loop(e);
	return (0);
}
