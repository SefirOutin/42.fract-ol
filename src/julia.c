/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:42:30 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 21:09:05 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	calculate_julia(t_pos pos, t_complex c, double new_re, double new_im)
{
	int	i;
	int	i_max;

	i = 0;
	i_max = 150 + pos.zoom * 10;
	while (i < i_max && new_re * new_re + new_im * new_im < 4)
	{
		operations(&new_re, &new_im, c.c_r, c.c_i);
		i++;
	}
	return (which_color(i, i_max));
}

void	julia_launch(t_img *img, t_pos pos, t_complex c)
{
	int		color;
	double	new_re;
	double	new_im;

	img->y = 0;
	while (img->y < WIN_H)
	{
		img->x = 0;
		while (img->x < WIN_W)
		{
			new_re = 1.5 * (img->x - WIN_W / 2) / (0.5 * pos.zoom * WIN_W)
				+ pos.xmove;
			new_im = (img->y - WIN_H / 2) / (0.5 * pos.zoom * WIN_H)
				+ pos.ymove;
			color = calculate_julia(pos, c, new_re, new_im);
			put_pixel_to_image(img, img->x, img->y, color);
			img->x++;
		}
		img->y++;
	}
}
