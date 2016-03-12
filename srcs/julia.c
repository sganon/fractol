/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/12 16:49:59 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	u.color = i * 7;
	p = x * 4 + y * e->sl;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
		e->j->img[p] = u.rgb.b;
		e->j->img[p + 1] = u.rgb.g;
		e->j->img[p + 2] = u.rgb.r;
	}
}

void	julia(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double tmp;

	x = 0;
	while (x < e->img_x)
	{
		y = 0;
		while (y < e->img_y)
		{
			e->j->z_r = x / e->j->zoom_x + e->j->min_x;
			e->j->z_i = y / e->j->zoom_y + e->j->min_y;
			i = 0;
			while (e->j->z_r * e->j->z_r + e->j->z_i * e->j->z_i <= 4 && i < e->j->i_max)
			{
				tmp = e->j->z_r;
				e->j->z_r = e->j->z_r * e->j->z_r - e->j->z_i * e->j->z_i + e->j->c_r;
				e->j->z_i = 2 * e->j->z_i * tmp + e->j->c_i;
				i++;
			}
			if (i != e->j->i_max)
				draw_color(e, i, x, y);
			y++;
		}
		x++;
	}
}
