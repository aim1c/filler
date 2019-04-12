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

void		set_enem(t_temrmap *t, t_box *b, t_f_map *map, int set)
{
	int		i;
	int		j;

	i = b->row;
	j = b->elem;
	if (j + 1 < map->x && t->content[i][j + 1] == ON)
		t->content[i][j + 1] = set;
	if (j > 0 && t->content[i][j - 1] == ON)
		t->content[i][j - 1] = set;
	if (i + 1 < map->y && t->content[i + 1][j] == ON)
		t->content[i + 1][j] = set;
	if (i > 0 && t->content[i - 1][j] == ON)
		t->content[i - 1][j] = set;
	if (i + 1 < map->y && j + 1 < map->x && t->content[i + 1][j + 1] == ON)
		t->content[i + 1][j + 1] = set;
	if (i > 0 && j + 1 < map->x && t->content[i - 1][j + 1] == ON)
		t->content[i - 1][j + 1] = set;
	if (i + 1 < map->y && j > 0 && t->content[i + 1][j - 1] == ON)
		t->content[i + 1][j - 1] = set;
	if (i > 0 && j > 0 && t->content[i - 1][j - 1] == ON)
		t->content[i - 1][j - 1] = set;
}

void		create_int_map(t_temrmap *t, int rows, int elems)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (t->content == NULL)
	{
		t->content = (int **)malloc(sizeof(int *) * (rows + 1));
		if (t->content == NULL)
			perror("Malloc = NULL");
		while (i <= rows)
		{
			t->content[i] = (int *)malloc(sizeof(int) * (elems + 1));
			if (t->content[i] == NULL)
				perror("Malloc[i] = NULL");
			i++;
		}
	}
}

void		remove_voids(t_temrmap *t, int rows_l, int elem_lim)
{
	int		i;
	int		j;

	i = -1;
	while (++i < rows_l)
	{
		j = -1;
		while (++j < elem_lim)
			if (t->content[i][j] == ON)
				t->content[i][j] = -1;
	}
}

void		heat_map_finish(t_temrmap *t, int rows_l, int elem_lim, t_f_map *m)
{
	t_box	li;
	int		sub;
	int		size;

	size = 100;
	li = (t_box){0, 0, 0, 0};
	sub = 0;
	while (--size > 0)
	{
		li.row = 0;
		while (li.row < rows_l)
		{
			li.elem = 0;
			while (li.elem < elem_lim)
			{
				if (t->content[li.row][li.elem] == sub)
					set_enem(t, &li, m, sub + 1);
				li.elem++;
			}
			li.row++;
		}
		sub++;
	}
	remove_voids(t, rows_l, elem_lim);
}

void		teplo_carta(t_f_map *map, t_temrmap *t, t_f_players *players)
{
	t_box	li;

	li = (t_box){0, 0, (int)map->y, (int)map->x};
	create_int_map(t, li.row_lim, li.elem_lim);
	while (li.row < li.row_lim)
	{
		li.elem = 0;
		while (li.elem < li.elem_lim)
		{
			if (map->content[li.row][li.elem] == '.')
				t->content[li.row][li.elem] = ON;
			else if (map->content[li.row][li.elem] == players->i)
				t->content[li.row][li.elem] = -1;
			else if (map->content[li.row][li.elem] == players->enemy)
				t->content[li.row][li.elem] = 0;
			li.elem++;
		}
		li.row++;
	}
	heat_map_finish(t, (int)map->y, (int)map->x, map);
}
