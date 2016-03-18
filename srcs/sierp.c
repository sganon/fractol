/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:02:44 by sganon            #+#    #+#             */
/*   Updated: 2016/03/18 17:59:21 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_color_sierp(t_env *e, int x, int y)
{
	t_color	u;
	int		p;

	if (e->c < 7)
		u.color = hsv_to_rgb(x, e);
	else
		u.color = x * 7;
	p = x * 4 + y * e->sl;
	if (check_for_x_y(x, y, e) && !e->s->img[p])
	{
		e->s->img[p] = u.rgb.b;
		e->s->img[p + 1] = u.rgb.g;
		e->s->img[p + 2] = u.rgb.r;
	}
}

void		triangle(int x, int y, int a, t_env *e)
{
	t_point	c;
	t_point	d;
	t_point	f;
	int		b;

	b = -a * sqrt(3) / 2;
	c.x = x;
	c.y = y;
	d.x = x + a;
	d.y = y;
	f.x = x + a / 2;
	f.y = y + b;
	ft_draw_line(c, d, e);
	ft_draw_line(c, f, e);
	ft_draw_line(f, d, e);
}

void		cut_triangle(int x, int y, int a, t_env *e)
{
	t_point	c;
	t_point	d;
	t_point	f;
	int		b;

	b = -a * sqrt(3) / 2;
	c.x = x + a / 2;
	c.y = y;
	d.x = x + 3 * a / 4;
	d.y = y + b / 2;
	f.x = x + a / 4;
	f.y = y + b / 2;
	ft_draw_line(c, d, e);
	ft_draw_line(c, f, e);
	ft_draw_line(d, f, e);
}

t_point		new_p(t_point p, int a, int b, int id)
{
	if (id == 1)
		return (p);
	if (id == 2)
	{
		p.x = p.x + a / 2;
		return (p);
	}
	if (id == 3)
	{
		p.x = p.x + a / 4;
		p.y = p.y + b / 2;
		return (p);
	}
	return (p);
}

void		sierp(t_env *e, t_point p, int a, int i)
{
	double	b;

	b = -a * sqrt(3) / 2;
	if (i > 0)
	{
		triangle(p.x, p.y, a, e);
		cut_triangle(p.x, p.y, a, e);
		sierp(e, new_p(p, a, b, 1), a / 2, i - 1);
		sierp(e, new_p(p, a, b, 2), a / 2, i - 1);
		sierp(e, new_p(p, a, b, 3), a / 2, i - 1);
	}
}
