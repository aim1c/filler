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

void		read_map(char *line, t_f_map *map)
{
	int		i;

	i = 0;
	if (ft_strnstr(line, "Plateau ", 8))
	{
		map->y = (size_t)ft_atoi(&line[8]);
		map->x = (size_t)ft_atoi(ft_strrchr(line, ' '));
		map->size = (int)(map->y * map->x);
	}
	map->content = (char **)malloc(sizeof(char *) * map->y + 1);
	ft_gnl(0, &line);
	line != NULL ? free(line) : 0;
	while (ft_gnl(0, &line) > -1 && map->y--)
	{
		map->content[i] = ft_strdup(&line[4]);
		line != NULL ? (free(line)) : 0;
		i++;
		if (map->y == 0)
			break ;
	}
	map->y = map->size / map->x;
	map->content[i] = 0;
}

void		read_token(char *line, t_f_map *token)
{
	int		i;

	i = 0;
	if (ft_strnstr(line, "Piece ", 6))
	{
		token->y = (size_t)ft_atoi(&line[6]);
		token->x = (size_t)ft_atoi(ft_strrchr(line, ' '));
		token->size = (int)(token->y * token->x);
	}
	line != NULL ? (free(line)) : 0;
	token->content = (char **)malloc(sizeof(char *) * token->y + 1);
	while (ft_gnl(0, &line) > -1 && token->y--)
	{
		token->content[i] = ft_strdup(line);
		line != NULL ? (free(line)) : 0;
		i++;
		if (token->y == 0)
			break ;
	}
	token->y = token->size / token->x;
	token->content[i] = 0;
}
