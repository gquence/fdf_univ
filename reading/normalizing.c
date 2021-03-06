/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:47:33 by gquence           #+#    #+#             */
/*   Updated: 2019/06/27 14:25:41 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_min_max(t_point *arr, double *pmax, double *pmin)
{
	double	min;
	double	max;
	double	buf;

	max = arr->coord.y;
	min = arr->coord.y;
	while (arr->coord.x != POINT_END)
	{
		buf = arr->coord.y;
		if (buf > max)
			max = buf;
		if (buf < min)
			min = buf;
		arr++;
	}
	*pmin = min;
	*pmax = max;
}

static void	normalize_y(t_point *arr, double max, double min)
{
	double	median;

	median = max - min;
	if (FT_ABS(max) < FT_ABS(min))
		median = -median;
	while (arr->coord.x != POINT_END)
	{
		arr->coord.y = (arr->coord.y - median / 2) / median * TOP_BORDER;
		arr++;
	}
}

int			normalize_arr_double(t_point *arr)
{
	double	max;
	double	min;
	int		i;

	i = 0;
	get_min_max(arr, &max, &min);
	normalize_y(arr, max, min);
	return (1);
}
