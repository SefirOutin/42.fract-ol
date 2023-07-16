/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:44:43 by soutin            #+#    #+#             */
/*   Updated: 2023/07/16 20:57:05 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_dimg {
	void	*img;
	int		*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_dimg;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_dimg	image;
}				t_vars;

typedef struct	s_plan
{
	double	Xmin;
	double	Xmax;
	double	Ymin;
	double	Ymax;
	int		x;
	int		y;
	double		dx;
	double		dy;
}				t_plan;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#define GREEN 0x00FF00
#define YELLOW 0xF6FA15
#define CYAN 0x15EFE5
#define MAGENTA 0xD03EC6
#define ORANGE 0xD35400
#define BLACK 0x000000

#define W_width 1280
#define W_heigh 720

#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../libft/include/libft.h"

void	mandelbrot_launch(t_dimg *img, double zoom);


#endif