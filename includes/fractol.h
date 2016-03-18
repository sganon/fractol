/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:34:21 by sganon            #+#    #+#             */
/*   Updated: 2016/03/18 18:30:40 by sganon           ###   ########.fr       */
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
# define KEY_R			15
# define STAR			67
# define SLASH			75
# define WHEEL_UP		4
# define WHEEL_DOWN		5

# define WIN_X			900
# define WIN_Y			900

# define EM(x)			e->m->x
# define EJ(x)			e->j->x
# define ES(x)			e->s->x
# define ESH(x)			e->sh->x

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

typedef struct			s_sierp
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					x;
	int					y;
	int					a;
	int					i;
	t_point				p;
}						t_sierp;

typedef struct			s_ship
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
}						t_ship;

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
	t_ship				*sh;
	int					mandel;
	int					jul;
	int					sierp;
	int					ship;
	int					c;
}						t_env;

int						init_env(t_env *e);
int						init_mandel(t_man *m, t_env *e);
int						init_julia(t_jul *j, t_env *e);
int						init_ship(t_ship *sh, t_env *e);
int						init_sierp(t_sierp *s, t_env *e);
int						sierp_key_events(int keycode, t_env *e);
int						mandel_key_events(int key, t_env *e);
int						julia_key_events(int key, t_env *e);
int						ship_key_events(int key, t_env *e);
int						mouse_events(int button, int x, int y, t_env *e);
int						julia_mouse_events(int button, int x, int y, t_env *e);
int						ship_mouse_events(int button, int x, int y, t_env *e);
int						sierp_mouse_events(int button, int x, int y, t_env *e);
int						move_c(int x, int y, t_env *e);
int						check_argv(int argc, char **argv, t_env *e);
void					mandel(t_env *e);
void					julia(t_env *e);
void					sierp(t_env *e, t_point p, int a, int i);
void					ship(t_env *e);
void					handle_color(t_env *e);
int						create_image(t_env *e);
int						expose_hook(t_env *e);
void					ft_error(int error);
int						rgb_create(double r, double g, double b);
int						hsv_to_rgb(int i, t_env *e);
int						check_for_x_y(int x, int y, t_env *e);
void					get_c_and_z(t_env *e, int x, int y);
void					ft_draw_line(t_point p1, t_point p2, t_env *e);
void					draw_color_sierp(t_env *e, int x, int y);
void					handle_fractal(t_env *e);
#endif
