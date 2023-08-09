/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:44:43 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 21:05:25 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct s_complex
{
	double		c_r;
	double		c_i;
}				t_complex;

typedef struct s_pos
{
	double		zoom;
	double		xmove;
	double		ymove;
}				t_pos;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bpp;
	int			line_l;
	int			endian;
	int			x;
	int			y;
}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		fractal;
	t_img		image;
	t_pos		pos;
	t_complex	c;
}				t_vars;

# define GREEN 0x00FF00
# define YELLOW 0xF6FA15
# define CYAN 0x15EFE5
# define MAGENTA 0xD03EC6
# define ORANGE 0xD35400
# define BLACK 0x000000

# define WIN_W 800
# define WIN_H 600

/*initialisations*/
int				init_vars(t_vars *vars, char fractal);
t_img			init_img(t_vars *vars);
int				init_mlx_features(t_vars *vars);
void			init_c_for_julia_next(t_vars *vars, int set_number);
void			init_c_for_julia(t_vars *vars, int set_number);
void			put_pixel_to_image(t_img *img, int x, int y, int color);

/**/
int				launch_first_fractal(t_vars *vars, char fractal);
void			mandelbrot_launch(t_img *img, t_pos pos);
void			julia_launch(t_img *img, t_pos pos, t_complex c);
int				which_color(int i, int max);
void			operations(double *new_re, double *new_im, double c_r,
					double c_i);

/*events handlers*/
int				mouse_event(int button, int x, int y, void *param);
int				key_inputs(int keysym, t_vars *vars);

/*events' functions*/
int				close_window(t_vars *vars);
void			zoom(t_vars *vars);
void			change_position(t_vars *vars, int direction);
void			change_mandelbrot_position(t_vars *vars, int direction);
void			change_julia_position(t_vars *vars, int direction);

#endif