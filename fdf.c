/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:09:15 by gquence           #+#    #+#             */
/*   Updated: 2019/07/04 15:40:46 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_point_colour(int start_colour, int end_colour, int diff)
{
	int	r;
	int	g;
	int	b;

	if (((int)diff) == 0 || start_colour == end_colour)
		return (end_colour);
	r = start_colour & 0x00ff0000;
	g = start_colour & 0x0000ff00;
	b = start_colour & 0x000000ff;
	r += ((end_colour & 0x00ff0000) - r) / diff;
	g += ((end_colour & 0x0000ff00) - g) / diff;
	b += ((end_colour & 0x000000ff) - b) / diff;
	return ((r & 0x00ff0000) | (g & 0x0000ff00) | (b & 0x000000ff));
}

t_mat3	get_scaling_matrix(double c)
{
	t_mat3	rt;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i == j)
				rt.elems[i][j] = c;
			else 
				rt.elems[i][j] = 0;
			j++;
		}
		i++;
	}
	return (rt);
}

t_mat3	get_rot_mat_xyz(double x, double y, double z)
{
	t_mat3	b;
	t_mat3	c;
	t_mat3	a;
	t_mat3	pr;
	t_mat3	r;

	a = get_rotate_mat_x(x);
	b = get_rotate_mat_y(y);
	c = get_rotate_mat_z(z);
	pr = matrices_multi(&a, &b);
	r = matrices_multi(&pr, &c);
	return (r);
}
