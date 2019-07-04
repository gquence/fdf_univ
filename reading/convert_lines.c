/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:23:47 by gquence           #+#    #+#             */
/*   Updated: 2019/06/27 14:25:01 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_fatoi(char **pstr, double *result)
{
	long long int	a;
	int				sign;
	char			*str;

	a = 0;
	sign = 0;
	str = *pstr;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? 1 : 0;
	while (ft_isdigit(*str))
		a = a * 10 + (*str++ - '0');
	if (*str && *str != ',')
		return (0);
	*result = (double)(sign ? -a : a);
	*pstr = str;
	return (1);
}

void		fill_pointarr(t_point *arr, int rows, int columns)
{
	double	counter_z;
	double	counter_x;
	int		x;
	int		z;
	int		i;

	i = 0;
	x = rows * columns;
	arr[x].coord.x = (double)POINT_END;
	counter_x = 2 * TOP_BORDER;
	counter_z = counter_x / (columns - 1);
	counter_x /= (rows - 1);
	x = 0;
	while (arr[i].coord.x != (double)POINT_END)
	{
		z = i % columns;
		if (i && !(i % columns))
			x++;
		arr[i].coord.x = x * counter_x - TOP_BORDER;
		arr[i].coord.z = z * counter_z - TOP_BORDER;
		i++;
	}
}

int			convertstrs(char ***splitted, t_point *arrpoints)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	i = 0;
	x = 0;
	while (*(splitted + x))
	{
		y = 0;
		while ((str = *(*(splitted + x) + y++)))
		{
			if (!ft_fatoi(&str, &arrpoints[i].coord.y))
				return (0);
			if (*str == ',')
				arrpoints[i].colour = ft_atoi_base((str + 1), 16);
			else if (!*str)
				arrpoints[i].colour = 0x00ffffff;
			else
				return (0);
			i++;
		}
		x++;
	}
	return (1);
}

t_point		*convert_allpoints(char ***splitted, int rows, int columns)
{
	t_point	*points;
	int		counter;

	counter = 0;
	points = (t_point *)malloc(sizeof(t_point) * (rows * columns + 1));
	fill_pointarr(points, rows, columns);
	if (!(convertstrs(splitted, points)))
	{
		free(points);
		return (NULL);
	}
	normalize_arr_double(points);
	return (points);
}
