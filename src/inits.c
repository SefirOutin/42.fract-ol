/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:19:40 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 20:42:21 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_mlx_features(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_event, vars);
	mlx_key_hook(vars->win, key_inputs, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
	return (0);
}

void	init_pos(t_pos *pos, char fractal)
{
	pos->zoom = 1;
	pos->moveY = 0;
	if (fractal == 'M' || fractal == 'm')
		pos->moveX = -0.5;
	else
		pos->moveX = 0;
}

t_img	init_img(t_vars *vars)
{
	t_img	new_img;

	new_img.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	if (!new_img.img)
		return (new_img);
	new_img.addr = (int *)mlx_get_data_addr(new_img.img, &new_img.bpp,
			&new_img.line_l, &new_img.endian);
	return (new_img);
}

int	init_vars(t_vars *vars, char fractal)
{
	vars->mlx = mlx_init();
	vars->fractal = fractal;
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fract-ol");
	if (!vars->win)
	{
		free(vars->mlx);
		return (1);
	}
	vars->image = init_img(vars);
	init_pos(&vars->pos, fractal);
	return (0);
}

int	launch_first_fractal(t_vars *vars, char fractal)
{
	if (init_vars(vars, fractal))
		return (1);
	if (fractal == 'M' || fractal == 'm')
		mandelbrot_launch(&vars->image, vars->pos);
	else if (fractal == 'J' || fractal == 'j')
		julia_launch(&vars->image, vars->pos, vars->c);
	return (0);
}
