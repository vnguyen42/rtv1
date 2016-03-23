/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:57:23 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/23 17:05:23 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	printf("keycode: %d\n", keycode);
	return (1);
}
