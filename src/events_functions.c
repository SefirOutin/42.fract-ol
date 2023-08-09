/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:08:55 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 19:46:44 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	zoom(t_vars *vars)
{
	t_img	new_img;

	if (vars->pos.zoom > 0)
	{
		new_img = init_img(vars);
		if (vars->fractal == 'M' || vars->fractal == 'm')
			mandelbrot_launch(&new_img, vars->pos);
		else if (vars->fractal == 'J' || vars->fractal == 'j')
			julia_launch(&new_img, vars->pos, vars->c);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->image.img);
		vars->image = new_img;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
}

void	change_mandelbrot_position(t_vars *vars, int direction)
{
	if (direction == 1)
		vars->pos.moveX -= 0.1;
	else if (direction == 2)
		vars->pos.moveY -= 0.1;
	else if (direction == 3)
		vars->pos.moveX += 0.1;
	else if (direction == 4)
		vars->pos.moveY += 0.1;
}

void	change_julia_position(t_vars *vars, int direction)
{
	if (direction == 1)
		vars->pos.moveX -= 0.01;
	else if (direction == 2)
		vars->pos.moveY -= 0.01;
	else if (direction == 3)
		vars->pos.moveX += 0.01;
	else if (direction == 4)
		vars->pos.moveY += 0.01;
}

void	change_position(t_vars *vars, int direction)
{
	t_img	new_img;

	new_img = init_img(vars);
	if (vars->fractal == 'm' || vars->fractal == 'M')
	{
		change_mandelbrot_position(vars, direction);
		mandelbrot_launch(&new_img, vars->pos);
	}
	else
	{
		change_julia_position(vars, direction);
		julia_launch(&new_img, vars->pos, vars->c);
	}
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->image.img);
	vars->image = new_img;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}
