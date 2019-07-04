/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:58:38 by gquence           #+#    #+#             */
/*   Updated: 2019/07/04 14:03:21 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	vec_mat_multi(const t_vec3_ptr v, const t_mat3_ptr m)
{
	return ((t_vec3){
			v->x * m->elems[0][0] + v->y * m->elems[1][0]
				+ v->z * m->elems[2][0],
			v->x * m->elems[0][1] + v->y * m->elems[1][1]
				+ v->z * m->elems[2][1],
			v->x * m->elems[0][2] + v->y * m->elems[1][2]
				+ v->z * m->elems[2][2]});
}

t_vec3	rotate_x(const t_vec3_ptr v, double x)
{
	t_mat3 a;

	a = get_rotate_mat_x(x);
	return (vec_mat_multi(v, &a));
}

t_vec3	rotate_y(const t_vec3_ptr v, double x)
{
	t_mat3 a;

	a = get_rotate_mat_y(x);
	return (vec_mat_multi(v, &a));
}

t_vec3	rotate_z(const t_vec3_ptr v, double x)
{
	t_mat3 a;

	a = get_rotate_mat_z(x);
	return (vec_mat_multi(v, &a));
}

t_vec3	rotate_xyz(const t_vec3_ptr v, double x, double y, double z)
{
	t_vec3 a;
	t_mat3 b;

	b = get_rotate_mat_x(x);
	a = vec_mat_multi(v, &b);
	b = get_rotate_mat_y(y);
	a = vec_mat_multi(&a, &b);
	b = get_rotate_mat_z(z);
	a = vec_mat_multi(&a, &b);
	return (a);
}
