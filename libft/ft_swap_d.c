/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:48:42 by gquence           #+#    #+#             */
/*   Updated: 2019/06/27 16:48:45 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_d(double *x, double *y)
{
	double	z;

	z = *x;
	*x = *y;
	*y = z;
}