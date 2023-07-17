/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:04:23 by soutin            #+#    #+#             */
/*   Updated: 2023/07/17 20:55:03 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_event(int button, int x, int y, void *param)
{
	static double	zoom = 1.0;

	ft_putnbr_fd(button, 1);
	if (button == 4)
		zoom = zoom + 0.1;
	else if (button == 5)
		zoom = zoom - 0.1;
	zoom_M((t_vars *)param, zoom);
	return (0);
}

int	inputs(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		//mlx_loop_end(vars->mlx);
		exit(0);
	}
	ft_putnbr_fd(keysym, 1);
	return(0);
}

int    close_window(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->image.img);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(0);
    return (0);
}
