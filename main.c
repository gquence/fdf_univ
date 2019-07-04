/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:53:34 by dmelessa          #+#    #+#             */
/*   Updated: 2019/07/04 15:43:13 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_image(void *param, t_point *points)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	i = 0;
	mlx_ptr = ((t_param_ptr)param)->mlx_ptr;
	win_ptr = ((t_param_ptr)param)->win_ptr;
	while (points[i + 1].coord.x != (double)POINT_END)
	{
		if (((i + 1) % (((t_param_ptr)param)->n_columns)))
			draw_brline(points[i], points[i + 1], param);
		if ((i + (((t_param_ptr)param)->n_columns)) <
				((t_param_ptr)param)->n_elems)
			draw_brline(points[i], points[i +
				((t_param_ptr)param)->n_columns], param);
		i++;
	}
	return (1);
}

t_point	*get_points(t_param_ptr pr)
{
	t_point	*points;
	t_mat3	a;
	t_mat3	b;
	int		i;

	if (!(points = (t_point *)malloc(sizeof(t_point) * (pr->n_elems + 1))))
		exit(0);
	points[pr->n_elems].coord.x = POINT_END;
	a = get_rot_mat_xyz(pr->angle_x, pr->angle_y, pr->angle_z);
	b = get_scaling_matrix(pr->scaling);
	i = 0;
	while (i < pr->n_elems)
	{
		points[i].coord = vec_mat_multi(&(pr->points[i].coord), &a);
		points[i].coord = vec_mat_multi(&(points[i].coord), &b);
		points[i].coord = get_transformed(&(points[i].coord));
		points[i].colour = pr->points[i].colour;
		i++;
	}
	return (points);
}

int		key_event(int keycode, void *param)
{
	t_point	*points;
	t_param	*pr;

	pr = (t_param_ptr)param;
	if (keycode == KEY_ESC || keycode == KEY_ESC_L)
	{
		mlx_destroy_window(pr->mlx_ptr, pr->win_ptr);
		free(pr->points);
		exit(0);
	}
	rotation(pr, keycode);
	projection(pr, keycode);
	scaling(pr, keycode);
	bonus(pr, keycode);
	points = get_points(pr);
	mlx_clear_window(pr->mlx_ptr, pr->win_ptr);
	draw_image(param, points);
	free(points);
	return (0);
}

/*
**	printf("x = %f, y = %f, z = %f\n", pr->angle_x, pr->angle_y, pr->angle_z);
*/

void	win_init(t_param_ptr pr)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FDF");
	pr->mlx_ptr = mlx_ptr;
	pr->win_ptr = win_ptr;
	pr->scaling = 1;
}

int		main(int ac, char **av)
{
	t_param param;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf \"filename\"");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl("There is no file with this name!");
		return (-1);
	}
	if (!read_field(fd, &param))
	{
		ft_putendl("Invalid file!");
		ft_putendl("Amounts of elements in every line must be equal.");
		ft_putendl("Form of every element \"position of elem, colour\"");
		return (-1);
	}
	win_init(&param);
	key_event(KEY_ONE, (void *)&param);
	mlx_key_hook(param.win_ptr, key_event, (void *)&param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
