/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:46:04 by sganon            #+#    #+#             */
/*   Updated: 2016/03/17 16:07:26 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

int		check_argv(int argc, char **argv, t_env *e)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	e->mandel = 0;
	e->jul = 0;
	e->sierp = 0;
	e->ship = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "Mandelbrot") == 0)
		{
			e->mandel = 1;
			c++;
		}
		else if (ft_strcmp(argv[i], "Julia") == 0)
		{
			e->jul = 1; 
			c++;
		}
		else if (ft_strcmp(argv[i], "Sierpinski") == 0)
		{
			e->sierp = 1; 
			c++;
		}
		else if (ft_strcmp(argv[i], "Ship") == 0)
		{
			e->ship = 1; 
			c++;
		}
	}
	if (c == 0)
		ft_error(1);
	return (1);
}
