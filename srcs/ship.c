/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:40:32 by sganon            #+#    #+#             */
/*   Updated: 2016/03/15 16:29:01 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	if (e->c < 7)
		u.color = HSV_to_RGB(i, e);
	else
		u.color = i * 6;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
		e->sh->img[p] = u.rgb.b;
		e->sh->img[p + 1] = u.rgb.g;
		e->sh->img[p + 2] = u.rgb.r;
	}
}

void	ship(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double tmp;

	x = 0;
	while (x < e->img_x - 1)
	{
		y = 0;
		while (y < e->img_y - 1)
		{
			e->sh->c_r = x / e->sh->zoom_x + e->sh->min_x;
			e->sh->c_i = y / e->sh->zoom_y + e->sh->min_y;
			e->sh->z_r = 0;
			e->sh->z_i = 0;
			i = 0;
			while (e->sh->z_r * e->sh->z_r + e->sh->z_i * e->sh->z_i <= 4 && i < e->sh->i_max)
			{
				tmp = e->sh->z_r;
				e->sh->z_r = ABS(e->sh->z_r * e->sh->z_r - e->sh->z_i * e->sh->z_i) + e->sh->c_r;
				e->sh->z_i = ABS(2 * e->sh->z_i * tmp) + e->sh->c_i;
				i++;
			}
			if (i != e->sh->i_max)
				draw_color(e, i, x, y);
			y++;
		}
		x++;
	}
}
