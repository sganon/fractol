/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:04:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/02 14:50:02 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (0);
	if (!(e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fract'ol")))
		return (0);
	e->min_x = -2.1;
	e->max_x = 0.6;
	e->min_y = -1.2;
	e->max_y = 1.2;
	e->img_x = WIN_X;
	e->img_y = WIN_Y;
	e->i_max = 42;
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
	e->img_ptr = NULL;
	e->img = NULL;
	return (1);
}

void	create_image(t_env *e)
{
	e->end = 0;
	e->bpp = 8;
	e->sl = WIN_X;
	e->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->img = mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->sl), &(e->end));
}
