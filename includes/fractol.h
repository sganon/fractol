/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:34:21 by sganon            #+#    #+#             */
/*   Updated: 2016/03/12 17:21:06 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define ESC			53
# define LEFT			123
# define RIGHT			124
# define UP				126
# define DOWN			125
# define MINUS			78
# define PLUS			69
# define KEY_C			8
# define KEY_I			34
# define STAR			67
# define SLASH			75
# define WHEEL_UP		4
# define WHEEL_DOWN		5

# define WIN_X		900
# define WIN_Y		900

# define EM(x)			e->m->x
# define EJ(x)			e->j->x

# define ABS(x)			((x) < 0 ? -(x) : (x))

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

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_sierp
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					x;
	int					y;
	int					a;
	int					i;
}						t_sierp;

typedef struct			s_man
{
	void				*win;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				zoom_x;
	double				zoom_y;
	void				*img_ptr;
	char				*img;
	int					i_max;
	double				x_complex;
	double				y_complex;
}						t_man;

typedef struct			s_jul
{
	void				*win;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				zoom_x;
	double				zoom_y;
	void				*img_ptr;
	char				*img;
	int					i_max;
}						t_jul;

typedef struct			s_env
{
	void				*mlx;
	double				r;
	double				img_x;
	double				img_y;
	int					end;
	int					bpp;
	int					sl;
	t_man				*m;
	t_jul				*j;
	t_sierp				*s;
	int					mandel;
	int					jul;
	int					sierp;
}						t_env;

int		init_env(t_env *e);
int		key_events(int keycode, t_env *e);
int		mouse_events(int button, int x, int y, t_env *e);
int		julia_mouse_events(int button, int x, int y, t_env *e);
int		move_c(int x, int y, t_env *e);
int		check_argv(int argc, char **argv, t_env *e);
void	mandel(t_env *e);
void	julia(t_env *e);
void	sierp(t_env *e, int x, int y, int a, int i);
void	create_image(t_env *e);
int		expose_hook(t_env *e);
void	ft_error(int error);
#endif
