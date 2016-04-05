/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:57:49 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/05 13:00:25 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void	clear_screen(t_env *env)
{
	t_point p;

	mlx_clear_window(env->mlx, env->win);
	env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	p.y = 0;
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			pixel_to_image(0x00000000, env,
					p.x, p.y);
			p.x++;
		}
		p.y++;
	}
}

void        pixel_to_image(unsigned long color, t_env *val, int x, int y)
{
	char    *image;
	int     bpp;
	int     size_line;
	int     endian;

	image = mlx_get_data_addr(val->img, &bpp, &size_line, &endian);
	val->r = ((color & 0xFF0000) >> 16);
	val->g = ((color & 0xFF00) >> 8);
	val->b = ((color & 0xFF));
	image[x * bpp / 8 + y * size_line] = val->b;
	image[x * bpp / 8 + 1 + y * size_line] = val->g;
	image[x * bpp / 8 + 2 + y * size_line] = val->r;
}
