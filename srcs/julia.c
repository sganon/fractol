/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 17:34:19 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	u.color = i * 5;
	p = x * 4 + y * e->sl;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
		e->j->jimg[p] = u.rgb.b;
		e->j->jimg[p + 1] = u.rgb.g;
		e->j->jimg[p + 2] = u.rgb.r;
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
			e->j->z_r = x / e->j->jzoom_x + e->j->jmin_x;
			e->j->z_i = y / e->j->jzoom_y + e->j->jmin_y;
			i = 0;
			while (e->j->z_r * e->j->z_r + e->j->z_i * e->j->z_i <= 4 && i < e->i_max)
			{
				tmp = e->j->z_r;
				e->j->z_r = e->j->z_r * e->j->z_r - e->j->z_i * e->j->z_i + e->j->j_c_r;
				e->j->z_i = 2 * e->j->z_i * tmp + e->j->j_c_i;
				i++;
			}
			if (i != e->i_max)
				draw_color(e, i, x, y);
			y++;
		}
		x++;
	}
}
