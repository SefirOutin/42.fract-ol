/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:43:05 by soutin            #+#    #+#             */
/*   Updated: 2023/08/09 20:57:21 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_help(void)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		ft_printf("-");
		i++;
	}
	ft_printf("\n");
	ft_printf("First param : J(j) / M(m)");
	ft_printf("\n");
	ft_printf("if you pick julia you can choose a set from 1 to 8");
	ft_printf("\n");
	ft_printf("Ex : ./fractol [letter] [set number]");
	ft_printf("\n");
	i = 0;
	while (i < 50)
	{
		ft_printf("-");
		i++;
	}
	ft_printf("\n");
}

int	check_params(int c, char **v)
{
	int	nb;

	if (c == 3)
		nb = ft_atoi(v[2]);
	if (c < 2 || c > 3)
		return (1);
	if ((*v[1] != 'm' && *v[1] != 'M' && *v[1] != 'j' && *v[1] != 'J'))
		return (1);
	if ((*v[1] == 'm' || *v[1] == 'M') && c != 2)
		return (1);
	if ((*v[1] == 'j' || *v[1] == 'J') && c != 3)
		return (1);
	if ((*v[1] == 'j' || *v[1] == 'J') && (nb < 1 || nb > 8))
		return (1);
	return (0);
}

int	main(int c, char **v)
{
	t_vars	vars;
	
	if (!check_params(c, v))
	{
		if (c == 3)
			init_c_for_julia(&vars, ft_atoi(v[2]));
		if (launch_first_fractal(&vars, *v[1]))
			return (0);
		init_mlx_features(&vars);
		free(vars.mlx);
	}
	else
		print_help();
	return (0);
}
