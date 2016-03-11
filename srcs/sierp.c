/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:02:44 by sganon            #+#    #+#             */
/*   Updated: 2016/03/11 18:57:25 by sganon           ###   ########.fr       */
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
		e->s->img[p] = u.rgb.b;
		e->s->img[p + 1] = u.rgb.g;
		e->s->img[p + 2] = u.rgb.r;
	}
}

void	triangle(int x, int y, int a, int b, t_env *e)
{
	int	s_x;
	int	s_y;
	int	c;

	c = 0;
	s_y = WIN_Y - 1;
	while (s_y > y + b)
	{
		s_x = WIN_X / 2 - 60 + c;
		while (s_x < x + a - c)
		{
			draw_color(e, s_x, s_y);
			s_x++;
		}
		s_y--;
	}
}

void	sierp(t_env *e, int x, int y, int a, int i)
{
	double	b;

	b = -a * sqrt(3) / 2;
	if (i > 0)
	{
		triangle(x, y, a, b, e);
	}
}
