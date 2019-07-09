/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:54:23 by gquence           #+#    #+#             */
/*   Updated: 2019/07/09 16:20:54 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_splittedlen(char **splitted)
{
	int	result;

	result = 0;
	if (!splitted)
		return (0);
	while (*splitted)
	{
		result++;
		splitted++;
	}
	return (result);
}

static char	***splited_join(char ****p_arrsplited, char *line, int count)
{
	char	***result;
	char	***buf;

	buf = *p_arrsplited;
	if (!(result = (char ***)malloc(sizeof(char **) * (count + 2))))
		return (NULL);
	result[count + 1] = NULL;
	if (!(result[count] = strsplit1(line)))
	{
		free(result);
		return (NULL);
	}
	if (buf[0] && get_splittedlen(result[count]) != get_splittedlen(buf[0]))
	{
		del_pp(&(result[count]));
		free(result);
		return (NULL);
	}
	while (--count != -1)
		result[count] = buf[count];
	free(*p_arrsplited);
	*p_arrsplited = result;
	return (result);
}

static char	***get_splitted(int fd, t_param_ptr params)
{
	char	*line;
	char	***splitted;
	int		counter1;
	int		counter2;

	params->n_lines = 0;
	splitted = (char ***)malloc(sizeof(char **));
	*splitted = NULL;
	counter1 = 0;
	while (get_next_line(fd, &line))
	{
		if (!(splited_join(&splitted, line, params->n_lines)) ||
			(counter1 != (counter2 = get_splittedlen(*splitted)) && counter1))
		{
			del_arr_splited(&splitted);
			free(line);
			return (NULL);
		}
		counter1 = counter2;
		ft_strdel(&line);
		(params->n_lines)++;
	}
	params->n_elems = params->n_lines;
	return (splitted);
}

int			read_field(int fd, t_param_ptr params)
{
	char	***splitted;

	if (!(splitted = get_splitted(fd, params)))
		return (0);
	params->n_columns = get_splittedlen(*splitted);
	params->n_elems *= params->n_columns;
	if (!(params->points = convert_allpoints(splitted,
		params->n_lines, params->n_columns)))
	{
		del_arr_splited(&splitted);
		return (0);
	}
	del_arr_splited(&splitted);
	return (1);
}
