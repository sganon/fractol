/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:34:21 by sganon            #+#    #+#             */
/*   Updated: 2016/02/24 16:23:25 by sganon           ###   ########.fr       */
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

# define WIN_X		900
# define WIN_Y		900

typedef unsigned char	t_bytes;

typedef struct			s_rgb
{
	t_bytes				b;
	t_bytes				g;
	t_bytes				r;
}						t_rgb;

typedef union			u_color
{
	size_t				color;
	t_rgb				rgb;
}						t_color;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				r;
	int					i_max;
	double				img_x;
	double				img_y;
	double				zoom_x;
	double				zoom_y;
	int					end;
	int					bpp;
	int					sl;
	void				*img_ptr;
	char				*img;
}						t_env;

int		init_env(t_env *e);
int		key_events(int keycode, t_env *e);
int		mouse_events(int button, int x, int y, t_env *e);
void	mandel(t_env *e);
void	create_image(t_env *e);
int		expose_hook(t_env *e);
#endif
