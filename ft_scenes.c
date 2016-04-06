/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scenes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:13:58 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/06 17:39:31 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "Libft/libft.h"

void    init_scene_1_2(t_rtv1 *k)
{
	k->spheres[2].radius = 100;
	k->spheres[2].material = 2;
	k->lights[0].pos.x = 0;
	k->lights[0].pos.y = 240;
	k->lights[0].pos.z = -100;
	k->lights[0].intensity.r = 1;
	k->lights[0].intensity.g = 1;
	k->lights[0].intensity.b = 1;
	k->lights[1].pos.x = 3200;
	k->lights[1].pos.y = 3000;
	k->lights[1].pos.z = -1000;
	k->lights[1].intensity.r = 0.6;
	k->lights[1].intensity.g = 0.7;
	k->lights[1].intensity.b = 1;
	k->lights[2].pos.x = 600;
	k->lights[2].pos.y = 0;
	k->lights[2].pos.z = -100;
	k->lights[2].intensity.r = 0.3;
	k->lights[2].intensity.g = 0.5;
	k->lights[2].intensity.b = 1;
}

void	init_scene_1(t_rtv1 *k)
{
	k->materials[0].diffuse.r = 1;
	k->materials[0].diffuse.g = 0;
	k->materials[0].diffuse.b = 0;
	k->materials[0].reflection = 0.2;
	k->materials[1].diffuse.r = 0;
	k->materials[1].diffuse.g = 1;
	k->materials[1].diffuse.b = 0;
	k->materials[1].reflection = 0.5;
	k->materials[2].diffuse.r = 0;
	k->materials[2].diffuse.g = 0;
	k->materials[2].diffuse.b = 1;
	k->materials[2].reflection = 0.9;
	k->spheres[0].pos.x = 200;
	k->spheres[0].pos.y = 300;
	k->spheres[0].pos.z = 0;
	k->spheres[0].radius = 100;
	k->spheres[0].material = 0;
	k->spheres[1].pos.x = 400;
	k->spheres[1].pos.y = 400;
	k->spheres[1].pos.z = 0;
	k->spheres[1].radius = 100;
	k->spheres[1].material = 1;
	k->spheres[2].pos.x = 500;
	k->spheres[2].pos.y = 140;
	k->spheres[2].pos.z = 0;
	init_scene_1_2(k);
}
