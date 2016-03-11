/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/11 16:30:09 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	u.color = i * 4;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
		e->m->img[p] = u.rgb.b;
		e->m->img[p + 1] = u.rgb.g;
		e->m->img[p + 2] = u.rgb.r;
	}
}

void	mandel(t_env *e)
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
			e->m->c_r = x / e->m->zoom_x + e->m->min_x;
			e->m->c_i = y / e->m->zoom_y + e->m->min_y;
			e->m->z_r = 0;
			e->m->z_i = 0;
			i = 0;
			while (e->m->z_r * e->m->z_r + e->m->z_i * e->m->z_i <= 4 && i < e->m->i_max)
			{
				tmp = e->m->z_r;
				e->m->z_r = e->m->z_r * e->m->z_r - e->m->z_i * e->m->z_i + e->m->c_r;
				e->m->z_i = 2 * e->m->z_i * tmp + e->m->c_i;
				i++;
			}
			if (i != e->m->i_max)
				draw_color(e, i, x, y);
			y++;
		}
		x++;
	}
}
