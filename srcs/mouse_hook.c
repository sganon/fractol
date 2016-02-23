/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/02/23 18:41:34 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean(t_env *e);

int		mouse_events(int button, int x, int y, t_env *e)
{
	double	k;

	(void)x;
	(void)y;
	k = 0.1;
	if (button == WHEEL_UP)
	{
		e->min_x += k;
		e->max_x -= k;
		e->min_y += k;;
		e->max_y -= k;
		e->i_max = e->i_max + 20;
	}	
	if (button == WHEEL_DOWN)
	{
		e->min_x -= k;
		e->max_x += k;
		e->min_y -= k;
		e->max_y += k;
		e->i_max = e->i_max - 20;
	}
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
	ft_clean(e);
	expose_hook(e);
	return (0);
}
