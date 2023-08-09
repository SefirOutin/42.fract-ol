/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:44:34 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 20:45:29 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_c_for_julia(t_vars *vars, int set_number)
{
	if (set_number < 5)
	{
		if (set_number == 1)
		{
			vars->c.c_r = -0.79;
			vars->c.c_i = 0.15;
		}
		else if (set_number == 2)
		{
			vars->c.c_r = -0.162;
			vars->c.c_i = 1.04;
		}
		else if (set_number == 3)
		{
			vars->c.c_r = 0.3;
			vars->c.c_i = -0.01;
		}
		else if (set_number == 4)
		{
			vars->c.c_r = -1.476;
			vars->c.c_i = 0;
		}	
	}
	else
		init_c_for_julia_next(vars, set_number);
}

void	init_c_for_julia_next(t_vars *vars, int set_number)
{
	if (set_number == 5)
	{
		vars->c.c_r = -0.12;
		vars->c.c_i = -0.77;
	}
	else if (set_number == 6)
	{
		vars->c.c_r = 0.28;
		vars->c.c_i = 0.008;
	}
	else if (set_number == 7)
	{
		vars->c.c_r = 0.360284;
		vars->c.c_i = 0.100376;
	}
	else if (set_number == 8)
	{
		vars->c.c_r = -0.75;
		vars->c.c_i = 0.1;
	}
}
