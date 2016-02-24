/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/02/24 18:50:37 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	u.color = i * 2;
	p = x * 4 + y * e->sl;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
		e->img[p] = u.rgb.b;
		e->img[p + 1] = u.rgb.g;
		e->img[p + 2] = u.rgb.r;
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
			if (i != e->i_max)
				draw_color(e, i, x, y);
			y++;
		}
		x++;
	}
}
