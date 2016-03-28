/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:06:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/28 19:03:43 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int	intersect_ray_sphere(t_ray *r, t_sphere *s)
{
	float		a;
	t_vector	dist;
	float 		b;
	float c;
	float discr;

	a = vector_dot(&r->dir, &r->dir);
	dist = vector_sub(&r->start, &s->pos);

	b = 2 * vector_dot(&r->dir, &dist);
	c = vector_dot(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	return (1);
}

t_vector vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector result;
	
	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

float	vector_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
