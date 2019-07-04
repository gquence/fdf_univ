/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:42:53 by gquence           #+#    #+#             */
/*   Updated: 2019/07/04 13:56:30 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat3	get_rotate_mat_z(double angle)
{
	double	sin_a;
	double	cos_a;
	t_mat3	result;

	sin_a = sin(angle * RAD);
	cos_a = cos(angle * RAD);
	result.elems[0][0] = cos_a;
	result.elems[0][1] = sin_a;
	result.elems[0][2] = 0;
	result.elems[1][0] = -sin_a;
	result.elems[1][1] = cos_a;
	result.elems[1][2] = 0;
	result.elems[2][0] = 0;
	result.elems[2][1] = 0;
	result.elems[2][2] = 1;
	return (result);
}

t_mat3	get_rotate_mat_y(double angle)
{
	double	sin_a;
	double	cos_a;
	t_mat3	result;

	sin_a = sin(angle * RAD);
	cos_a = cos(angle * RAD);
	result.elems[0][0] = cos_a;
	result.elems[0][1] = 0;
	result.elems[0][2] = -sin_a;
	result.elems[1][0] = 0;
	result.elems[1][1] = 1;
	result.elems[1][2] = 0;
	result.elems[2][0] = sin_a;
	result.elems[2][1] = 0;
	result.elems[2][2] = cos_a;
	return (result);
}

t_mat3	get_rotate_mat_x(double angle)
{
	double	sin_a;
	double	cos_a;
	t_mat3	result;

	sin_a = sin(angle * RAD);
	cos_a = cos(angle * RAD);
	result.elems[0][0] = 1;
	result.elems[0][1] = 0;
	result.elems[0][2] = 0;
	result.elems[1][0] = 0;
	result.elems[1][1] = cos_a;
	result.elems[1][2] = sin_a;
	result.elems[2][0] = 0;
	result.elems[2][1] = -sin_a;
	result.elems[2][2] = cos_a;
	return (result);
}

t_vec3	get_transformed(const t_vec3_ptr v)
{
	return ((t_vec3){
		(v->x + 1.0f) * X_FACTOR,
		(-v->y + 1.0f) * Y_FACTOR,
		v->z});
}

t_mat3	matrices_multi(const t_mat3_ptr mat1, const t_mat3_ptr mat2)
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
			rt.elems[i][j] = mat1->elems[i][0] * mat2->elems[0][j] +
				mat1->elems[i][1] * mat2->elems[1][j] +
					mat1->elems[i][2] * mat2->elems[2][j];
			j++;
		}
		i++;
	}
	return (rt);
}
