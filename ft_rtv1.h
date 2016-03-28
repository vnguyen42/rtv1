/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:00:47 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/28 19:04:12 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct  	s_point
{
	int x;
	int y;
	int z;
}               	t_point;

typedef struct		s_vector
{
	float x;
	float y;
	float z;
}					t_vector;

typedef struct		s_sphere
{
	t_vector	pos;
	float		radius;
}					t_sphere;

typedef struct		s_colour
{
	float r;
	float g;
	float b;
}

typedef struct		s_ray
{
	t_vector start;
	t_vector dir;
}					t_ray;

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
int					intersect_ray_sphere(t_ray *r, t_sphere *s);
t_vector			vector_sub(t_vector *v1, t_vector *v2);
float				vector_dot(t_vector *v1, t_vector *v2);

#endif
