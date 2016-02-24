/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:39:05 by sganon            #+#    #+#             */
/*   Updated: 2016/02/24 15:12:28 by sganon           ###   ########.fr       */
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
			e->img[p] = 0;
			e->img[p + 1] = 0;
			e->img[p + 2] = 0;
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	if (e->img == NULL)
		create_image(e);
	mandel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_do_sync(e->mlx);
	ft_clean(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	(void)argc;
	(void)argv;

	e = (t_env *)malloc(sizeof(t_env));
	if (!(init_env(e)))
		return (0);
	mlx_key_hook(e->win, key_events, e);
	mlx_mouse_hook(e->win, mouse_events, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_do_sync(e->mlx);
	mlx_loop(e->mlx);
	return (0);
}
