/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:39:05 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 16:24:56 by sganon           ###   ########.fr       */
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
			e->jimg[p] = 0;
			e->jimg[p + 1] = 0;
			e->jimg[p + 2] = 0;
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	if (e->img == NULL || e->jimg == NULL)
		create_image(e);
	mandel(e);
	julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->jwin, e->jimg_ptr, 0, 0);
	mlx_do_sync(e->mlx);
	ft_clean(e);
	return (0);
}

int		move_c(int x, int y, t_env *e)
{
	double		x_complex;
	double		y_complex;

	if (x <= WIN_X && y <= WIN_Y)
	{
	if (x > (WIN_X / 2))
		x_complex = (x - (WIN_X / 2)) * (e->max_x / (WIN_X / 2));
	else
		x_complex = (x - (WIN_X / 2)) * ((-e->min_x / 2) / (WIN_X / 4));
	if (y > (WIN_Y / 2))
		y_complex = ((WIN_Y / 2) - y) * (-e->min_y / (WIN_Y / 2));
	else
		y_complex = ((WIN_Y / 2) - y) * ((e->max_y / 2) / (WIN_Y / 4));
	e->j_c_r = x_complex;
	e->j_c_i = y_complex;
	expose_hook(e);
	return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	(void)argc;
	(void)argv;

	e = (t_env *)malloc(sizeof(t_env));
	if (!(init_env_for_mandel(e)) || !(init_env_for_julia(e)))
		return (0);
	mlx_key_hook(e->win, key_events, e);
	mlx_hook(e->win, 6, (1L<<6), move_c, e);
	mlx_mouse_hook(e->win, mouse_events, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->jwin, key_events, e);
	//mlx_mouse_hook(e->jwin, mouse_events, e);
	mlx_expose_hook(e->jwin, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
