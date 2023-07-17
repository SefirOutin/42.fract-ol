/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:32:06 by soutin            #+#    #+#             */
/*   Updated: 2023/07/17 20:58:54 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	hm_color(int i, int max)
{
	int	color;
	static int h = 0;

	if (i == max)
		return BLACK ;
	else
	{
		h++;
		if (i < max / 10)
			color = BLACK;
		else if (i < max / 7.5)
			color = YELLOW + h;
		else if (i < max / 5)
			color = CYAN + h;
		else if (i < max / 2.5)
			color = GREEN + h;
		else if (i < max / 1.5)
			color = ORANGE + h;
		else
			color = MAGENTA+h;
	}
	return (color);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int pixel_index;

	pixel_index = y * img->line_l + x * (img->bpp / 8);
    ((img->addr))[pixel_index / (img->bpp / 8)] = color;
}

t_plane	init_plane(double zoom)
{
	t_plane	plane;

	plane.Xmin = -2.0;
	plane.Xmax = 0.6;
	plane.Ymin = -1.2;
	plane.Ymax = 1.2;
	plane.x = 0;
	plane.y = 0;
	plane.dx = ((plane.Xmax - plane.Xmin) / WIN_W) * zoom;
	plane.dy = ((plane.Ymax - plane.Ymin) / WIN_H) * zoom;
	return (plane);
}

int	calc(t_plane plane, double zoom)
{
	double	z_r;
	double	z_i;
	int		i;
	double	tmp;
	int		i_max;
	
	i_max = 200 * zoom;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (i < i_max && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + (plane.x * plane.dx + plane.Xmin);
		z_i = 2 * z_i * tmp + (plane.y * plane.dy + plane.Ymin);
		i++;
	}
	return (hm_color(i, i_max));
}

void	mandelbrot_launch(t_img *img, double zoom)
{
	img->plane = init_plane(zoom);

	while (img->plane.y < WIN_H)
	{
		img->plane.x = 0;
		while (img->plane.x < WIN_W)
		{
			put_pixel_to_image(img, img->plane.x, img->plane.y, calc(img->plane, zoom));
			img->plane.x++;
		}
		img->plane.y++;
	}
}
