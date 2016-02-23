/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:34:21 by sganon            #+#    #+#             */
/*   Updated: 2016/02/23 14:19:00 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <math.h>

# define ESC			53
# define LEFT			123
# define RIGHT			124
# define UP				126
# define DOWN			125
# define MINUS			78
# define PLUS			69
# define KEY_C			8
# define STAR			67
# define SLASH			75

# define WIN_X		1920
# define WIN_Y		1080

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

int		init_env(t_env *e);
int		key_events(int keycode, t_env *e);
#endif
