/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:06:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/06 17:28:15 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int	intersect_ray_sphere(t_ray *r, t_sphere *s, float t)
{
	t_irs k;

	k.a = vector_dot(&r->dir, &r->dir);
	k.dist = vector_sub(&r->start, &s->pos);

	k.b = 2 * vector_dot(&r->dir, &k.dist);
	k.c = vector_dot(&k.dist, &k.dist) - (s->radius * s->radius);
	k.discr = k.b * k.b - 4 * k.a * k.c;
	if (k.discr < 0)
		return (0);
	else
	{
		k.sqrtdiscr = sqrt(k.discr);
		k.t0 = (-k.b + k.sqrtdiscr)/2;
		k.t1 = (-k.b - k.sqrtdiscr)/2;
		if (k.t0 > k.t1)
			k.t0 = k.t1;
		if ((k.t0 > 0.001f) && (k.t0 < t))
		{
			t = k.t0;
			return (1);
		}
		else
			return (0);
	}
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

t_vector	vector_scale(float c, t_vector *v)
{
	t_vector result;

	result.x = v->x *c;
	result.y = v->y *c;
	result.z = v->z * c;
	return (result);
}

t_vector	vector_add(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}
