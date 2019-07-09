/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:08:44 by gquence           #+#    #+#             */
/*   Updated: 2019/07/09 15:28:25 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angles(t_param_ptr pr, double x, double y, double z)
{
	pr->angle_x = x;
	pr->angle_y = y;
	pr->angle_z = z;
}

void	rotation(t_param_ptr pr, int keycode)
{
	if (keycode == KEY_Q || keycode == KEY_Q_L)
		pr->angle_z += 5;
	if (keycode == KEY_E || keycode == KEY_E_L)
		pr->angle_z -= 5;
	if (keycode == KEY_W || keycode == KEY_W_L)
		pr->angle_x += 5;
	if (keycode == KEY_S || keycode == KEY_S_L)
		pr->angle_x -= 5;
	if (keycode == KEY_A || keycode == KEY_A_L)
		pr->angle_y += 5;
	if (keycode == KEY_D || keycode == KEY_D_L)
		pr->angle_y -= 5;
}

void	projection(t_param_ptr pr, int keycode)
{
	if (keycode == KEY_ONE || keycode == KEY_ONE_L)
		angles(pr, -30, 30, -10);
	if (keycode == KEY_TWO || keycode == KEY_TWO_L)
		angles(pr, -30, 43, -15);
}

void	scaling(t_param_ptr pr, int keycode)
{
	if (keycode == KEY_ZERO || keycode == KEY_ZERO_L)
		pr->scaling = 1;
	if (keycode == KEY_PLUS || keycode == KEY_PLUS_L)
		pr->scaling += 0.05;
	if (keycode == KEY_MINUS || keycode == KEY_MINUS_L)
		pr->scaling -= 0.05;
}

void	bonus(t_param_ptr pr, int keycode)
{
	if (keycode == KEY_J || keycode == KEY_J_L)
		angles(pr, -90, 0, 0);
	if (keycode == KEY_U || keycode == KEY_U_L)
		pr->angle_x += 180;
	if (keycode == KEY_K || keycode == KEY_K_L)
		angles(pr, 0, 90, 0);
	if (keycode == KEY_I || keycode == KEY_I_L)
		pr->angle_y += 180;
	if (keycode == KEY_L || keycode == KEY_L_L)
		angles(pr, 0, 0, 0);
	if (keycode == KEY_O || keycode == KEY_O_L)
		pr->angle_z += 180;
}
