/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:13:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/16 16:11:01 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_color(t_env *e)
{	
		e->c++;
		if (e->c > 7)
			e->c = 0;
}

void	handle_pos(t_man *ptr, int i)
{
	if (key == UP)
	{
		ptr->min_y += 20;
		ptr->max_y += 20;
	}
	if (key == DOWN)
	{
		ptr->min_y -= 20;
		ptr->max_y -= 20;
	}
	if (key == RIGHT)
	{
		ptr->min_x += 20;
		ptr->max_x += 20;
	}
	if (key == LEFT)
	{
		ptr->min_x -= 20;
		ptr->max_x -= 20;
	}
}

int		mandel_key_events(int key, t_env *e)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
		handle_color(e);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		hendle_pos(e->m, 1);
	expos_hook(e);
}

int		key_events(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);

	if (keycode == KEY_I && e->sierp)
	{
		e->s->i++;
		expose_hook(e);
	}
	return (0);
}
