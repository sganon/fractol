/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:13:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/19 14:07:44 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_color(t_env *e)
{
	e->c++;
	if (e->c > 7)
		e->c = 0;
}

void	handle_pos(int key, t_man *ptr)
{
	double	x_dif;
	double	y_dif;

	x_dif = ABS(ptr->max_x - ptr->min_x);
	y_dif = ABS(ptr->max_y - ptr->min_y);
	if (key == UP)
	{
		ptr->min_y -= y_dif / 5;
		ptr->max_y -= y_dif / 5;
	}
	if (key == DOWN)
	{
		ptr->min_y += y_dif / 5;
		ptr->max_y += y_dif / 5;
	}
	if (key == RIGHT)
	{
		ptr->min_x += x_dif / 5;
		ptr->max_x += x_dif / 5;
	}
	if (key == LEFT)
	{
		ptr->min_x -= x_dif / 5;
		ptr->max_x -= x_dif / 5;
	}
}

int		mandel_key_events(int key, t_env *e)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
		handle_color(e);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		handle_pos(key, e->m);
	if (key == KEY_R)
		init_mandel(e->m, e);
	if (key == KEY_H)
		e->help = !e->help ? 1 : 0;
	expose_hook(e);
	return (1);
}

void	handle_sierp_pos(int key, t_sierp *ptr)
{
	if (key == UP)
	{
		ptr->y -= 20;
		ptr->y -= 20;
	}
	if (key == DOWN)
	{
		ptr->y += 20;
		ptr->y += 20;
	}
	if (key == RIGHT)
	{
		ptr->x += 20;
		ptr->x += 20;
	}
	if (key == LEFT)
	{
		ptr->x -= 20;
		ptr->x -= 20;
	}
}

int		sierp_key_events(int key, t_env *e)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_I)
		e->s->i++;
	if (key == KEY_C)
		handle_color(e);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		handle_sierp_pos(key, e->s);
	if (key == KEY_R)
		init_sierp(e->s, e);
	if (key == KEY_H)
		e->help = !e->help ? 1 : 0;
	expose_hook(e);
	return (0);
}
