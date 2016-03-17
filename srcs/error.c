/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:36:21 by sganon            #+#    #+#             */
/*   Updated: 2016/03/17 17:35:03 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
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
