/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:44:43 by soutin            #+#    #+#             */
/*   Updated: 2023/07/17 20:57:38 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
//#include "../minilibx-linux/mlx_int.h"
# include "../libft/include/libft.h"

typedef struct s_plane
{
	double	Xmin;
	double	Xmax;
	double	Ymin;
	double	Ymax;
	int		x;
	int		y;
	double	dx;
	double	dy;
}			t_plane;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_l;
	int		endian;
	t_plane	plane;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	image;
}			t_vars;


# define GREEN 0x00FF00
# define YELLOW 0xF6FA15
# define CYAN 0x15EFE5
# define MAGENTA 0xD03EC6
# define ORANGE 0xD35400
# define BLACK 0x000000

# define WIN_W 1000
# define WIN_H 900

void		mandelbrot_launch(t_img *img, double zoom);
void		zoom_M(t_vars *vars, double zoom);
int			mouse_event(int button, int x, int y, void *param);
int			inputs(int keysym, t_vars *vars);
int			close_window(t_vars *vars);

#endif