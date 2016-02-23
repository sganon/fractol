/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/02/23 16:58:06 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_events(int button, int x, int y, t_env *e)
{
	(void)e;
	if (button)
	{
		ft_putstr("Button");
		ft_putnbr(button);
		ft_putchar('\n');
		ft_putstr("x");
		ft_putnbr(x);
		ft_putchar('\n');
		ft_putstr("y");
		ft_putnbr(y);
		ft_putchar('\n');
	}
	return (0);
}
