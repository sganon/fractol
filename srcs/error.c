/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:36:21 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 18:59:55 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
	if (error == 0)
		ft_putendl("Please enter between 1 and 3 arguments.");
	ft_putendl("Valid arguments:\tMandelbrot;\n\t\t\tJulia;");
	exit(0);
}