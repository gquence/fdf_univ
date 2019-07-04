/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:37:46 by gquence           #+#    #+#             */
/*   Updated: 2019/06/27 14:38:09 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		del_pp(char ***pparr)
{
	char	**parr;

	if (!pparr || !*pparr)
		return (0);
	parr = *pparr;
	while (*parr)
	{
		ft_memdel((void **)parr);
		parr++;
	}
	parr = *pparr;
	free(parr);
	return (1);
}

void	del_arr_splited(char ****p_arrsplited)
{
	int		counter;
	char	***arr_splited;

	counter = 0;
	arr_splited = *p_arrsplited;
	while (*arr_splited)
	{
		del_pp(arr_splited);
		arr_splited++;
	}
	free(*p_arrsplited);
}
