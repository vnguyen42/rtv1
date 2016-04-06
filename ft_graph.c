/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:58:26 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/06 17:38:05 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "Libft/libft.h"

void	draw_grid(t_env *env, int clear)
{
	draw_scene(env, clear);
}

void	init_pixel_vars(t_rtv1 *k, int x, int y)
{
	k->red = 0;
	k->green = 0;
	k->blue = 0;
	k->level = 0;
	k->coef = 1.0;
	k->r.start.x = x;
	k->r.start.y = y;
	k->r.dir.x = 0;
	k->r.dir.y = 0;
	k->r.dir.z = 0;
}

int		calculate_shadow(t_rtv1 *k)
{
	int				in_shadow;
	unsigned int	p;

	in_shadow = 0;
	p = 0;
	while (p < 3)
	{
		if (intersect_ray_sphere(&k->light_ray, &k->spheres[p], k->t))
		{
			in_shadow = 1;
			break;
		}
		p++;
	}
	if (!in_shadow)
	{
		k->lambert = vector_dot(&k->light_ray.dir, &k->n) * k->coef;
		k->red += k->lambert * k->current_light.intensity.r *
			k->current_mat.diffuse.r;
		k->green += k->lambert * k->current_light.intensity.g *
			k->current_mat.diffuse.g;
		k->blue += k->lambert * k->current_light.intensity.b *
			k->current_mat.diffuse.b;
	}
	return (1);
}

int		value_of_light(t_rtv1 *k)
{
	unsigned int	j;
	float			t;
	int 			slide;

	j = 0;
	slide = 1;
	while (j < 3)
	{
		k->current_light = k->lights[j];
		k->dist = vector_sub(&k->current_light.pos, &k->new_start);
		slide = (vector_dot(&k->n, &k->dist) <= 0.0f) ? 0 : 1;
		if (slide)
		{
			t = sqrtf(vector_dot(&k->dist, &k->dist));
			slide = (t <= 0.0f) ? 0 : 1;
			if (slide)
			{
				k->light_ray.start = k->new_start;
				k->light_ray.dir = vector_scale((1/t), &k->dist);
				calculate_shadow(k);
			}
		}
		j++;
	}
	return (1);
}

int		ray_calculator(t_rtv1 *k)
{
	int i;

	k->t = 20000.0f;
	k->current_sphere = -1;
	i = 0;
	while (i < 3)
	{
		if (intersect_ray_sphere(&k->r, &k->spheres[i], k->t))
			k->current_sphere = i;
		i++;	
	}
	if (k->current_sphere == -1)
		return (0);
	k->scaled = vector_scale(k->t, &k->r.dir);
	k->new_start = vector_add(&k->r.start, &k->scaled);
	k->n = vector_sub(&k->new_start, &k->spheres[k->current_sphere].pos);
	k->temp = vector_dot(&k->n, &k->n);
	if (k->temp == 0)
		return (0);
	k->current_mat = k->materials[k->spheres[k->current_sphere].material];
	return (1);
}

void	draw_scene(t_env *env, int clear)
{
	t_rtv1 k;
	int x;
	int y;

	init_scene_1(&k);
	if (clear)
		clear_screen(env);
	y = 0;
	while (y < WIN_WIDTH)
	{
		x = 0;
		init_pixel_vars(&k, x, y); 
		while (x < WIN_HEIGHT)
		{
			
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
