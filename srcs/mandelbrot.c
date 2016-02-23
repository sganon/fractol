/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/02/23 15:58:56 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel_var(t_env *e)
{
	e->min_x = -2.6;
	e->max_x = 0.6;
	e->min_y = -1.2;
	e->max_y = 1.2;
	e->img_x = 270;
	e->img_y = 240;
	e->i_max = 50;
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
}

void	mandel(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double tmp;

	init_mandel_var(e);
	x = 0;
	while (x < e->img_x)
	{
		y = 0;
		while (y < e->img_y)
		{
			e->c_r = x / e->zoom_x + e->min_x;
			e->c_i = y / e->zoom_y + e->min_y;
			e->z_r = 0;
			e->z_i = 0;
			i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i <= 4 && i < e->i_max)
			{
				tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
				i++;
			}
			if (e->i_max == i)
				mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
			else
				mlx_pixel_put(e->mlx, e->win, x, y, i * 200);
				
			y++;
		}
		x++;
	}
}
