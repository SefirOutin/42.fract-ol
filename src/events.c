/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:04:23 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 20:41:55 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_event(int button, int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	ft_putnbr_fd(button, 1);
	if (button == 4)
		vars->pos.zoom += 0.05;
	else if (button == 5)
		vars->pos.zoom -= 0.05;
	zoom(vars);
	return (0);
}

int	key_inputs(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		close_window(vars);
	else if (keysym == XK_Left)
		change_position(vars, 1);
	else if (keysym == XK_Up)
		change_position(vars, 2);
	else if (keysym == XK_Right)
		change_position(vars, 3);
	else if (keysym == XK_Down)
		change_position(vars, 4);
	ft_putnbr_fd(keysym, 1);
	return (0);
}
