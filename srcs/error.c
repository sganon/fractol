/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:36:21 by sganon            #+#    #+#             */
/*   Updated: 2016/03/18 11:58:23 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
	if (error == -1)
		exit(0);
	if (error == 0)
		ft_putendl("Please enter between 1 and 4 arguments.");
	ft_putendl("Valid arguments:\tMandelbrot;\n\t\t\tJulia;");
	ft_putendl("\t\t\tSierpinski;\n\t\t\tShip;");
	exit(0);
}

int		check_for_x_y(int x, int y, t_env *e)
{
	if (x <= 0 || x >= WIN_X)
		return (0);
	if (y <= 0 || y >= WIN_Y)
		return (0);
	if (x * 4 + y * e->sl > WIN_X * 4 + WIN_Y * e->sl)
		return (0);
	return (1);
}

void	init_bool(t_env *e)
{
	e->mandel = 0;
	e->jul = 0;
	e->sierp = 0;
	e->ship = 0;
}

int		check_argv(int argc, char **argv, t_env *e)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	init_bool(e);
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "Mandelbrot") == 0)
			e->mandel = 1;
		if (ft_strcmp(argv[i], "Julia") == 0)
			e->jul = 1;
		if (ft_strcmp(argv[i], "Sierpinski") == 0)
			e->sierp = 1;
		if (ft_strcmp(argv[i], "Ship") == 0)
			e->ship = 1;
		if (e->mandel || e->jul || e->sierp || e->ship)
			c++;
	}
	return (c);
}
