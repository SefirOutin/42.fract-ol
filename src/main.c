/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:43:57 by soutin            #+#    #+#             */
/*   Updated: 2023/07/16 21:25:50 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	inputs(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	ft_putnbr_fd(keysym, 1);
	return (0);
}

int	mouse_event(int button, int x, int y, void *param)
{
	double	zoom;

	zoom = 1.0;
	ft_putnbr_fd(button, 1);
	if (button == 4)
	{
		zoom = zoom + 0.2;
		mandelbrot_launch((t_dimg *)param, zoom);
	}
	return (0);
}

int	initialisation(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, W_width, W_heigh, "hello world");
	if (!vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (1);
	}
	vars->image.img = mlx_new_image(vars->mlx, W_width, W_heigh);
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
	
	mandelbrot_launch(&vars.image, 1);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	
	mlx_mouse_hook(vars.win, &mouse_event, vars.image.img);
	mlx_key_hook(vars.win, &inputs, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	return (0);
}