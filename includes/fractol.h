/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:34:21 by sganon            #+#    #+#             */
/*   Updated: 2016/02/23 16:56:02 by sganon           ###   ########.fr       */
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
# define WHEEL_UP		4
# define WHEEL_DOWN		5

# define WIN_X		1920
# define WIN_Y		1080

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			r;
	int				i_max;
	double			img_x;
	double			img_y;
	double			zoom_x;
	double			zoom_y;
}					t_env;

int		init_env(t_env *e);
int		key_events(int keycode, t_env *e);
int		mouse_events(int button, int x, int y, t_env *e);
void	mandel(t_env *e);
#endif
