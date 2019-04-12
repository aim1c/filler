/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:47:04 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/02/19 23:47:06 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	del_maps(void **cont, size_t li, size_t lj)
{
	int i;

	i = -1;
	while (++i < (int)li)
	{
		ft_bzero(cont[i], lj);
		if (cont[i] != NULL)
		{
			free(cont[i]);
			cont[i] = NULL;
		}
	}
	cont != NULL ? (free(cont)) : 0;
	cont = NULL;
}

void	del_heat(t_filler *fil, int **heat, int li)
{
	int i;

	i = -1;
	while (++i < li)
	{
		ft_bzero(heat[i], (size_t)fil->map.x);
		if (heat[i] != NULL)
		{
			free(heat[i]);
			heat[i] = NULL;
		}
	}
	heat != NULL ? (free(heat)) : 0;
	heat = NULL;
}

void	del_all(t_filler *fil)
{
	del_maps((void **)fil->map.content, fil->map.y, fil->map.x);
	del_maps((void **)fil->token.content, fil->token.y, fil->token.x);
}
