/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/18 12:53:13 by sganon           ###   ########.fr       */
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

int			rgb_create(double r, double g, double b)
{
	t_color	u;

	u.rgb.r = r * 255;
	u.rgb.g = g * 255;
	u.rgb.b = b * 255;
	return (u.color);
}

int			hsv_to_rgb(int i, t_env *e)
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
		color = rgb_create(1 + m, x + m, m);
	else if (h >= 60.0 && h < 120.0)
		color = rgb_create(x + m, 1 + m, m);
	else if (h >= 120.0 && h < 180.0)
		color = rgb_create(m, 1 + m, x + m);
	else if (h >= 180.0 && h < 240.0)
		color = rgb_create(m, x + m, 1 + m);
	else if (h >= 240.0 && h < 300.0)
		color = rgb_create(x + m, m, 1 + m);
	else
		color = rgb_create(1 + m, m, x + m);
	return (color);
}

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	if (e->c < 7)
		u.color = hsv_to_rgb(i, e);
	else
		u.color = i * 6;
	if (check_for_x_y(x, y, e))
	{
		e->m->img[p] = u.rgb.b;
		e->m->img[p + 1] = u.rgb.g;
		e->m->img[p + 2] = u.rgb.r;
	}
}

void		mandel(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	x = -1;
	while (++x < e->img_x)
	{
		y = -1;
		while (++y < e->img_y)
		{
			get_c_and_z(e, x, y);
			i = 0;
			while (pow(e->m->z_r, 2) + pow(e->m->z_i, 2) <= 4 && i < EM(i_max))
			{
				tmp = e->m->z_r;
				e->m->z_r = pow(e->m->z_r, 2) - pow(e->m->z_i, 2) + e->m->c_r;
				e->m->z_i = 2 * e->m->z_i * tmp + e->m->c_i;
				i++;
			}
			if (i != e->m->i_max)
				draw_color(e, i, x, y);
		}
	}
}
