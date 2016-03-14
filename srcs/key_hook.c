/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:13:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/14 13:17:12 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_events(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 0;
		expose_hook(e);
	}
	if (keycode == KEY_I && e->sierp)
	{
		e->s->i++;
		expose_hook(e);
	}
	return (0);
}
