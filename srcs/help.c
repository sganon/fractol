/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:46:20 by sganon            #+#    #+#             */
/*   Updated: 2016/03/19 14:24:53 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_help(t_env *e, void *win)
{
	char	*mouse;
	char	*i;
	char	*julia;

	mouse = ft_strdup("Mouse click or wheel to zoom");
	i = ft_strdup("I to increase max indentation");
	julia = ft_strdup("Move mouse to change julia parameter");
	if (e->help)
	{
		mlx_string_put(e->mlx, win, 10, 10, 0xFFFFFF, "H to hide");
		mlx_string_put(e->mlx, win, 10, 30, 0xFFFFFF, "Arrows to move");
		mlx_string_put(e->mlx, win, 10, 50, 0xFFFFFF, mouse);
		mlx_string_put(e->mlx, win, 10, 70, 0xFFFFFF, "C for color");
		mlx_string_put(e->mlx, win, 10, WIN_Y - 30, 0xFFFFFF, "R to reset");
		mlx_string_put(e->mlx, win, 10, WIN_Y - 50, 0xFFFFFF, i);
		mlx_string_put(e->mlx, win, 10, WIN_Y - 70, 0xFFFFFF, julia);
		mlx_string_put(e->mlx, win, WIN_X - 120, 10, 0xFFFFFF, "ESC to quit");
	}
}

void	handle_win_help(t_env *e)
{
	if (e->mandel)
		display_help(e, e->m->win);
	if (e->jul)
		display_help(e, e->j->win);
	if (e->sierp)
		display_help(e, e->s->win);
	if (e->ship)
		display_help(e, e->sh->win);
}
