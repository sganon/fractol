/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:02:44 by sganon            #+#    #+#             */
/*   Updated: 2016/03/16 15:50:23 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color_sierp(t_env *e, int x, int y)
{
	t_color	u;
	int		p;

	u.color = y * 80;
	p = x * 4 + y * e->sl;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
			e->s->img[p] = u.rgb.b;
			e->s->img[p + 1] = u.rgb.g;
			e->s->img[p + 2] = u.rgb.r;
	}
}
void	ft_draw_line(t_point p1, t_point p2, t_env *e)
{
	t_point		d;
	t_point		s;
	int			err;
	int			e2;

	d.x = ABS(p2.x - p1.x);
	d.y = ABS(p2.y - p1.y);
	s.x = p1.x < p2.x ? 1 : -1;
	s.y = p1.y < p2.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		draw_color_sierp(e, p1.x, p1.y);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -d.x && ((err -= d.y) || !err))
			p1.x += s.x;
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}

void	triangle(int x, int y, int a, int b, t_env *e)
{
	t_point	A;
	t_point	B;
	t_point	C;

	A.x = x;
	A.y = y;
	B.x = x + a;
	B.y = y;
	C.x = x + a / 2;
	C.y = y + b;

	ft_draw_line(A, B, e);
	ft_draw_line(A, C, e);
	ft_draw_line(C, B, e);
}

void	cut_triangle(int x, int y, int a, int b, t_env *e)
{
	t_point	A;
	t_point	B;
	t_point	C;

	A.x = x + a / 2;
	A.y = y;
	B.x = x + 3 * a / 4;
	B.y = y + b / 2;
	C.x = x + a / 4;
	C.y = y + b / 2;	

	ft_draw_line(A, B, e);
	ft_draw_line(A, C, e);
	ft_draw_line(B, C, e);
}

void	sierp(t_env *e, int x, int y, int a, int i)
{
	double	b;

	b = -a * sqrt(3) / 2;
	if (i > 0)
	{
		triangle(x, y, a, b, e);
		cut_triangle(x, y, a, b, e);
		sierp(e ,x, y, a / 2, i - 1);
		sierp(e ,x + a / 2, y, a / 2, i - 1);
		sierp(e ,x + a / 4, y + b / 2, a / 2, i - 1);
	}
}
