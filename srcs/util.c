/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:49:19 by sganon            #+#    #+#             */
/*   Updated: 2016/03/19 14:32:17 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean(t_env *e)
{
	int		p;

	p = -1;
	while (++p < WIN_X * 4 + WIN_Y * e->sl)
	{
		e->m->img[p] = 0;
		e->j->img[p] = 0;
		e->s->img[p] = 0;
		e->sh->img[p] = 0;
	}
}

int		expose_hook(t_env *e)
{
	create_image(e);
	if (e->mandel)
	{
		mandel(e);
		mlx_put_image_to_window(e->mlx, e->m->win, e->m->img_ptr, 0, 0);
	}
	if (e->jul)
	{
		julia(e);
		mlx_put_image_to_window(e->mlx, e->j->win, e->j->img_ptr, 0, 0);
	}
	if (e->sierp)
	{
		sierp(e, e->s->p, e->s->a, e->s->i);
		mlx_put_image_to_window(e->mlx, e->s->win, e->s->img_ptr, 0, 0);
	}
	if (e->ship)
	{
		ship(e);
		mlx_put_image_to_window(e->mlx, e->sh->win, e->sh->img_ptr, 0, 0);
	}
	handle_win_help(e);
	ft_clean(e);
	mlx_do_sync(e->mlx);
	return (0);
}

void	handle_fractal(t_env *e)
{
	if (e->mandel)
	{
		mlx_key_hook(EM(win), mandel_key_events, e);
		mlx_mouse_hook(EM(win), mouse_events, e);
		mlx_expose_hook(EM(win), expose_hook, e);
	}
	if (e->jul)
	{
		mlx_key_hook(EJ(win), julia_key_events, e);
		mlx_mouse_hook(EJ(win), julia_mouse_events, e);
		mlx_expose_hook(EJ(win), expose_hook, e);
		if (!(e->mandel))
			mlx_hook(EJ(win), 6, (1L << 6), move_c, e);
	}
	if (e->sierp)
	{
		mlx_key_hook(e->s->win, sierp_key_events, e);
		mlx_mouse_hook(e->s->win, sierp_mouse_events, e);
		mlx_expose_hook(e->s->win, expose_hook, e);
	}
	if (e->jul && e->mandel)
		mlx_hook(EM(win), 6, (1L << 6), move_c, e);
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

int		create_image(t_env *e)
{
	if (!e->m->img || !e->j->img || !e->s->img || !e->sh->img)
	{
		e->end = 0;
		e->bpp = 8;
		e->sl = WIN_X;
		e->m->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
		e->j->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
		e->s->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
		e->sh->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
		if (!EM(img_ptr) || !EJ(img_ptr) || !ES(img_ptr) || !ESH(img_ptr))
			ft_error(-1);
		EM(img) = IMG_ADDR(EM(img_ptr), &(e->bpp), &(e->sl), &(e->end));
		EJ(img) = IMG_ADDR(EJ(img_ptr), &(e->bpp), &(e->sl), &(e->end));
		ES(img) = IMG_ADDR(ES(img_ptr), &(e->bpp), &(e->sl), &(e->end));
		ESH(img) = IMG_ADDR(ESH(img_ptr), &(e->bpp), &(e->sl), &(e->end));
		return (1);
	}
	return (0);
}
