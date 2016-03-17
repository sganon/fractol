/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/17 18:00:16 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		get_h(int i, t_env *e)
{
	if (e->c == 1)
		return (cos(i % 360) * (i % 360));
	else if (e->c == 2)
		return ((i * i) % 360);
	else if (e->c == 3)
		return (fmod(M_PI * i, 360));
	else if (e->c == 4)
		return (i % 90 + 200);
	else if (e->c == 5)
		return (i % 150 + 120);
	else if (e->c == 6)
		return (fmod(exp(i), 360));
	return (i % 360);
}

int			RGB_Create(double r, double g, double b)
{
	t_color	u;

	u.rgb.r = r * 255;
	u.rgb.g = g * 255;
	u.rgb.b = b * 255;
	return (u.color);
}

int			HSV_to_RGB(int i, t_env *e)
{
	double		h;
	double		x;
	double		m;
	int			color;

	h = get_h(i, e);
	x = (1 - fabs(fmod(h / 60, 2) - 1));
	m = 1 - 1;
	if (h >= 360)
		color = 0;
	else if (h >= 0.0 && h < 60.0)
		color = RGB_Create(1 + m, x + m, m);
	else if (h >= 60.0 && h < 120.0)
		color = RGB_Create(x + m, 1 + m, m);
	else if (h >= 120.0 && h < 180.0)
		color = RGB_Create(m, 1 + m, x + m);
	else if (h >= 180.0 && h < 240.0)
		color = RGB_Create(m, x + m, 1 + m);
	else if (h >= 240.0 && h < 300.0)
		color = RGB_Create(x + m, m, 1 + m);
	else 
		color = RGB_Create(1 + m, m, x + m);
	return (color);
}

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	if (e->c < 7)
		u.color = HSV_to_RGB(i, e);
	else
		u.color = i * 6;
	if (check_for_x_y(x, y, e))
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
