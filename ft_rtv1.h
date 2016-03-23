/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:00:47 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/23 17:04:07 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct  s_point
{
	int x;
	int y;
	int z;
}               t_point;

typedef struct		s_line
{
	double x;
	double y;
	double length;
	double addx;
	double addy;
}					t_line;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		r;
	int		g;
	int		b;
	void	*screen;
	float	rotation;
	float	hauteur;
	int		tmp;
	t_point	pos;
	int		color;
	t_point dimensions;
}					t_env;

int					init_rtv1();
void				draw_grid(t_env *env, int clear);
int					ft_key_handler(int keycode, void *param);
void				pixel_to_image(unsigned long color, t_env *val,
		int x, int y);
void				clear_screen(t_env *env);

#endif
