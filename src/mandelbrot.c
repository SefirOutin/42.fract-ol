/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:32:06 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 20:43:06 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	calculate_mandelbrot(t_pos pos, double c_r, double c_i)
{
	double	new_re;
	double	new_im;
	int		i;
	int		i_max;

	i_max = 150 + pos.zoom * 10;
	new_re = 0;
	new_im = 0;
	i = 0;
	while (i < i_max && new_re * new_re + new_im * new_im < 4)
	{
		operations(&new_re, &new_im, c_r, c_i);
		i++;
	}
	return (which_color(i, i_max));
}

void	mandelbrot_launch(t_img *img, t_pos pos)
{
	int		color;
	double	c_r;
	double	c_i;

	img->y = 0;
	while (img->y < WIN_H)
	{
		img->x = 0;
		while (img->x < WIN_W)
		{
			c_r = 1.5 * (img->x - WIN_W / 2) / (0.5 * pos.zoom * WIN_W)
				+ pos.moveX;
			c_i = (img->y - WIN_H / 2) / (0.5 * pos.zoom * WIN_H) + pos.moveY;
			color = calculate_mandelbrot(pos, c_r, c_i);
			put_pixel_to_image(img, img->x, img->y, color);
			img->x++;
		}
		img->y++;
	}
}
