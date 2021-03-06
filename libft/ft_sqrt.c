/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 00:41:51 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/15 14:16:48 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(int a)
{
	float	y;

	y = a / 2;
	while (1)
	{
		if (ABS(y * y - a) < 0.001)
			break ;
		y = (a / y + y) / 2;
	}
	return (y);
}
