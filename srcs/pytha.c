/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pytha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:26:07 by sganon            #+#    #+#             */
/*   Updated: 2016/03/10 18:16:01 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_color(t_env *e, int x, int y)
{
	t_color	u;
	int		p;

	u.color = 0xFFFFFF;
	p = x * 4 + y * e->sl;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X && p < WIN_X * WIN_Y * e->bpp)
	{
		e->p->img[p] = u.rgb.b;
		e->p->img[p + 1] = u.rgb.g;
		e->p->img[p + 2] = u.rgb.r;
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
		draw_color(e, p1.x, p1.y);
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

void	pytha(t_env *e)
{
	int	start_x;
	int	start_y;
	int	h;

	start_y = WIN_Y - 1;
	while (start_y > (WIN_Y - 120))
	{
		start_x = WIN_X / 2 - 60;
		while (start_x < WIN_X / 2 + 60)
		{
			draw_color(e, start_x, start_y);
			start_x++;
		}
		start_y--;
	}
	h = sqrt(((120 * 0.5 * M_SQRT2) * (120 * 0.5 * M_SQRT2)) -((102 / 2) * (102 / 2)));
	draw_color(e, (WIN_X / 2), (WIN_Y - 120 - h));
}
