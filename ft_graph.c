/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:58:26 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/23 16:59:12 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "Libft/libft.h"

void	draw_grid(t_env *env, int clear)
{
	t_point p;

	if (clear)
		clear_screen(env);
	p.x = 0;
	p.y = 0;
	p.z = 0;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
