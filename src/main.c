/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:43:57 by soutin            #+#    #+#             */
/*   Updated: 2023/07/17 21:17:09 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_img	init_img(t_vars *vars)
{
	t_img new_img;

	new_img.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	// if (!new_img.img)
	// 	return ;
	new_img.addr = (int *)mlx_get_data_addr(new_img.img, &new_img.bpp, &new_img.line_l, &new_img.endian);
	return (new_img);
}

void	zoom_M(t_vars *vars, double zoom)
{
	t_img	new_img;

	new_img = init_img(vars);
	mandelbrot_launch(&new_img, zoom);
	mlx_clear_window(vars->mlx, vars->win);
	vars->image = new_img;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	mlx_loop(vars->mlx);
}

int	initialisation(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "hello world");
	if (!vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (1);
	}
	vars->image.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	if (!vars->image.img)
		return (1);
	vars->image.addr = (int *)mlx_get_data_addr(vars->image.img, &vars->image.bpp, &vars->image.line_l, &vars->image.endian);
	// ft_printf("img : %p, bpp : %d, len : %d, endian : %d\n", &vars->image.img, vars->image.bpp, vars->image.line_l, vars->image.endian);
	
	return (0);
}

int	main()
{
	t_vars	vars;

	initialisation(&vars);
	
	mandelbrot_launch(&vars.image, 1.0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_key_hook(vars.win, inputs, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	return (0);
}