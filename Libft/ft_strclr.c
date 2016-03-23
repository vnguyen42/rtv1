/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:13:34 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:43 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int a;

	a = 0;
	if (s != NULL)
	{
		if (s[a] != '\0')
		{
			while (s[a])
			{
				s[a] = '\0';
				a++;
			}
		}
	}
}
