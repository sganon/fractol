/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/13 16:59:17 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_color(int i)
{
	int	h;
	int	c;
	int	x;
	int	m;
	t_color	u;

	h = i * i % 360;
	c = 1;
	m = 0;
	x = c * (1 - ABS((h / 60) % 2 - 1));
	if (h < 0 && h < 60)
	{
		u.rgb.b = 0;
		u.rgb.g = x;
		u.rgb.r = c;
	}
	if (h <= 60 && h < 120)
	{
		u.rgb.b = 0;
		u.rgb.g = c;
		u.rgb.r = x;
	}
	if (h <= 120 && h < 180)
	{
		u.rgb.b = x;
		u.rgb.g = c;
		u.rgb.r = 0;
	}
	if (h <= 180 && h < 240)
	{
		u.rgb.b = c;
		u.rgb.g = x;
		u.rgb.r = 0;
	}
	if (h <= 240 && h < 300)
	{
		u.rgb.b = c;
		u.rgb.g = 0;
		u.rgb.r = x;
	}
	if (h <= 300 && h < 360)
	{
		u.rgb.b = x;
		u.rgb.g = 0;
		u.rgb.r = c;
	}
	u.rgb.r = (u.rgb.r + m) * 255;
	u.rgb.g = (u.rgb.g + m) * 255;
	u.rgb.b = (u.rgb.b + m) * 255;
	return (u.color);
}

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	u.color = get_color(i);
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
