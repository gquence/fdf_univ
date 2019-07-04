/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:15:13 by gquence           #+#    #+#             */
/*   Updated: 2019/07/04 13:09:37 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horis(t_point start, t_point end, t_param par, t_diff *diff)
{
	int	colour;

	if (start.coord.y > end.coord.y)
	{
		ft_swap_d(&start.coord.x, &end.coord.x);
		ft_swap_d(&start.coord.y, &end.coord.y);
		ft_swap(&start.colour, &end.colour);
	}
	colour = start.colour;
	while (start.coord.y++ <= end.coord.y)
	{
		colour = get_point_colour(colour, end.colour, (diff->dy)--);
		mlx_pixel_put(par.mlx_ptr, par.win_ptr,
			start.coord.x, start.coord.y, colour);
	}
}

void	draw_vert(t_point start, t_point end, t_param par, t_diff *diff)
{
	int	colour;

	if (start.coord.x > end.coord.x)
	{
		ft_swap_d(&start.coord.x, &end.coord.x);
		ft_swap_d(&start.coord.y, &end.coord.y);
		ft_swap(&start.colour, &end.colour);
	}
	colour = start.colour;
	while (start.coord.x++ <= end.coord.x)
	{
		colour = get_point_colour(colour, end.colour, (diff->dx)--);
		mlx_pixel_put(par.mlx_ptr, par.win_ptr,
			start.coord.x, start.coord.y, colour);
	}
}

/*
**	рисует линию с коэфициентом наклона < 1
*/

void	draw_xline(t_point start, t_point end, t_param par, t_diff *diff)
{
	float	grad;
	float	intery;
	int		colour;

	if (start.coord.x > end.coord.x)
	{
		ft_swap_d(&start.coord.x, &end.coord.x);
		ft_swap_d(&start.coord.y, &end.coord.y);
		ft_swap(&start.colour, &end.colour);
	}
	colour = start.colour;
	grad = diff->dy / diff->dx;
	intery = grad + start.coord.y;
	grad = (start.coord.y > end.coord.y) ? -grad : grad;
	diff->dx = sqrt((diff->dx * diff->dx + diff->dy * diff->dy));
	while (start.coord.x++ < end.coord.x)
	{
		colour = get_point_colour(colour, end.colour, (diff->dx)--);
		mlx_pixel_put(par.mlx_ptr, par.win_ptr,
			(int)start.coord.x, (int)intery, colour);
		intery += grad;
	}
}

void	draw_yline(t_point start, t_point end, t_param par, t_diff *diff)
{
	float	grad;
	float	interx;
	int		colour;

	if (start.coord.y > end.coord.y)
	{
		ft_swap_d(&start.coord.x, &end.coord.x);
		ft_swap_d(&start.coord.y, &end.coord.y);
		ft_swap(&start.colour, &end.colour);
	}
	colour = start.colour;
	grad = diff->dx / diff->dy;
	interx = grad + (double)start.coord.x;
	grad = (start.coord.x > end.coord.x) ? -grad : grad;
	diff->dx = sqrt(diff->dx * diff->dx + diff->dy * diff->dy);
	while (start.coord.y++ < end.coord.y)
	{
		colour = get_point_colour(colour, end.colour, (diff->dx)--);
		mlx_pixel_put(par.mlx_ptr, par.win_ptr, (int)interx,
			(int)start.coord.y, colour);
		interx += grad;
	}
}

void	draw_brline(t_point start, t_point end, void *p_params)
{
	t_diff	diff;
	t_param	params;

	params = *((t_param_ptr)p_params);
	diff.dx = (end.coord.x > start.coord.x) ?
		(end.coord.x - start.coord.x) : (start.coord.x - end.coord.x);
	diff.dy = (end.coord.y > start.coord.y) ?
		(end.coord.y - start.coord.y) : (start.coord.y - end.coord.y);
	if (diff.dx == 0)
		draw_horis(start, end, params, &diff);
	else if (diff.dy == 0)
		draw_vert(start, end, params, &diff);
	else if (diff.dx > diff.dy)
		draw_xline(start, end, params, &diff);
	else
		draw_yline(start, end, params, &diff);
}
