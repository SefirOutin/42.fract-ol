/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:35:54 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 19:54:27 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	which_color(int i, int max)
{
	int			color;
	static int	h;

	h = 0;
	if (i == max)
		return (BLACK);
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
			color = MAGENTA + h;
	}
	return (color);
}

void	operations(double *new_re, double *new_im, double Cr, double Ci)
{
	double	old_re;
	double	old_im;

	old_re = *new_re;
	old_im = *new_im;
	*new_re = old_re * old_re - old_im * old_im + Cr;
	*new_im = 2 * old_im * old_re + Ci;
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = y * img->line_l + x * (img->bpp / 8);
	((img->addr))[pixel_index / (img->bpp / 8)] = color;
}
