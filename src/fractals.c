/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:32:06 by soutin            #+#    #+#             */
/*   Updated: 2023/07/16 21:25:11 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	hm_color(int i, int max)
{
	int	color;

	if (i == max)
		return BLACK ;
	else
		if (i < max / 10)
			color = 0xFFFFFF;
		else if (i < max / 7.5)
			color = YELLOW;
		else if (i < max / 5)
			color = CYAN;
		else if (i < max / 2.5)
			color = GREEN;
		else if (i < max / 1.5)
			color = ORANGE;
		else
			color = MAGENTA;
	return (color);
}

void	put_pixel_to_image(t_dimg *img, int x, int y, int color)
{
	int pixel_index;

	pixel_index = y * img->line_l + x * (img->bpp / 8);
    ((img->addr))[pixel_index / (img->bpp / 8)] = color;
}

t_plan	init_plan(double zoom)
{
	t_plan	plan;

	plan.Xmin = -2.1;
	plan.Xmax = 0.6;
	plan.Ymin = -1.2;
	plan.Ymax = 1.2;
	plan.x = 0;
	plan.y = 0;
	plan.dx = (plan.Xmax - plan.Xmin) * (135 + zoom);
	plan.dy = (plan.Ymax - plan.Ymin) * (135 + zoom);
	return (plan);
}

int	calc(t_plan plan)
{
	double	z_r;
	double	z_i;
	int		i;
	double	tmp;
	
	z_r = 0;
	z_i = 0;
	i = 0;
	while (i < 50 && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + (plan.x / plan.dx + plan.Xmin);
		z_i = 2 * z_i * tmp + (plan.y / plan.dy + plan.Ymin);
		i++;
	}
	return (hm_color(i, 50));
}

void	mandelbrot_launch(t_dimg *img, double zoom)
{
	t_plan plan = init_plan(zoom);

	while (plan.y < W_heigh)
	{
		plan.x = 0;
		while (plan.x < W_width)
		{
			put_pixel_to_image(img, plan.x, plan.y, calc(plan));
			plan.x++;
		}
		plan.y++;
	}
}
