/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:47:34 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/05 13:00:30 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_rtv1.h"
#include <unistd.h>

int		ft_translucid(void *param)
{
	t_env *env;

	env = param;
	draw_grid(env, 1);
	return (1);
}

void	init_env_vars(t_env *env)
{
	(void)(env);
}

int		init_rtv1()
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_do_key_autorepeaton(&env);
	init_env_vars(&env);
	mlx_loop_hook(env.mlx, ft_translucid, &env);
	mlx_key_hook(env.win, ft_key_handler, &env);
	mlx_loop(env.mlx);
	return (1);
}
