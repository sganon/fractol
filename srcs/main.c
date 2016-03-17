/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:39:05 by sganon            #+#    #+#             */
/*   Updated: 2016/03/16 16:07:09 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean(t_env *e)
{
	int		y;
	int		x;
	int		p;

	p = 0;
	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			p = x * 4 + y * e->sl;
			e->m->img[p] = 0;
			e->m->img[p + 1] = 0;
			e->m->img[p + 2] = 0;
			e->j->img[p] = 0;
			e->j->img[p + 1] = 0;
			e->j->img[p + 2] = 0;
			e->s->img[p] = 0;
			e->s->img[p + 1] = 0;
			e->s->img[p + 2] = 0;
			e->sh->img[p] = 0;
			e->sh->img[p + 1] = 0;
			e->sh->img[p + 2] = 0;
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	if (e->m->img == NULL || e->j->img == NULL || e->s->img == NULL || e->sh == NULL)
		if (create_image(e) == 0)
			return (0);
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
		sierp(e, e->s->x, e->s->y, e->s->a, e->s->i);
		ft_putendl("d8\n");
		mlx_put_image_to_window(e->mlx, e->s->win, e->s->img_ptr, 0, 0);
		ft_putendl("d9\n");
	}
	if (e->ship)
	{
		ship(e);
		mlx_put_image_to_window(e->mlx, e->sh->win, e->sh->img_ptr, 0, 0);
	}
	mlx_do_sync(e->mlx);
	ft_clean(e);
	return (0);
}



int		main(int argc, char **argv)
{
	t_env	*e;

	ft_putendl("d1\n");
	if (argc <= 1 || argc > 5)
		ft_error(0);
	ft_putendl("d2\n");
	e = (t_env *)malloc(sizeof(t_env));
	ft_putendl("d3\n");
	check_argv(argc, argv, e);
	ft_putendl("d4\n");
	if (!(init_env(e)))
		return (0);
	ft_putendl("d5\n");
	if (e->mandel)
	{
		mlx_key_hook(EM(win), mandel_key_events, e);
		mlx_mouse_hook(EM(win), mouse_events, e);
		mlx_expose_hook(EM(win), expose_hook, e);
	}
	if (e->jul)
	{
		mlx_key_hook(EJ(win), key_events, e);
		mlx_mouse_hook(EJ(win), julia_mouse_events, e);
		mlx_expose_hook(EJ(win), expose_hook, e);
		if (!(e->mandel))
			mlx_hook(EJ(win), 6, (1L<<6), move_c, e);
	}
	if (e->sierp)
	{
		mlx_key_hook(e->s->win, key_events, e);
		mlx_expose_hook(e->s->win, expose_hook, e);
		mlx_mouse_hook(e->s->win, sierp_mouse_events, e);
	}
	ft_putendl("d6\n");
	if (e->ship)
	{
		mlx_key_hook(e->sh->win, key_events, e);
		mlx_expose_hook(e->sh->win, expose_hook, e);
		mlx_mouse_hook(e->sh->win, ship_mouse_events, e);
	}
	if (e->jul && e->mandel)
		mlx_hook(EM(win), 6, (1L<<6), move_c, e);
	mlx_loop(e->mlx);
	ft_putendl("d7\n");
	return (0);
}
