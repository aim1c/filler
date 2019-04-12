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

void	star_dot(t_sa *ans, int state)
{
	if (state == PLAYERS)
	{
		ans->size++;
		ans->count++;
	}
	if (state == DOT)
	{
		ans->size++;
	}
}

int		can_put(t_filler *fll, t_f_map *tkn, t_f_map *map, t_boxx *pm)
{
	t_boxx	tk;
	t_sa	ans;

	tk = (t_boxx){-1, -1, (int)tkn->y, (int)tkn->x};
	ans = (t_sa){0, 0};
	while (++tk.i < tk.li)
	{
		tk.j = -1;
		while (++tk.j < tk.lj)
		{
			if (pm->i + tk.i < pm->li && pm->j + tk.j < pm->lj)
			{
				tkn->content[tk.i][tk.j] == '.' ? ans.size++ : 0;
				if (tkn->content[tk.i][tk.j] == '*'
					&& map->content[pm->i + tk.i][pm->j + tk.j] == fll->play.i)
					star_dot(&ans, PLAYERS);
				else if (tkn->content[tk.i][tk.j] == '*'
						&& map->content[pm->i + tk.i][pm->j + tk.j] == '.')
					star_dot(&ans, DOT);
			}
		}
	}
	if (ans.count == 1 && ans.size == tkn->size)
		return (1);
	return (0);
}

int		check_sum(int **cnt, t_f_map *tkn, t_boxx *pm, t_answ *answ)
{
	int		i;
	int		j;
	int		sum1;

	i = -1;
	sum1 = 0;
	while (++i < tkn->y)
	{
		j = -1;
		while (++j < tkn->x)
			if (tkn->content[i][j] == '*')
				sum1 += cnt[i + pm->i][j + pm->j];
	}
	if (sum1 < answ->sum)
	{
		answ->sum = sum1;
		answ->row = pm->i;
		answ->colum = pm->j;
	}
	return (1);
}

int		place_token_map(t_filler *fl)
{
	t_boxx pm;

	pm = (t_boxx){-1, -1, (int)fl->map.y, (int)fl->map.x};
	fl->answ.sum = ON * 3;
	while (pm.i++ < pm.li)
	{
		pm.j = -1;
		while (pm.j++ < pm.lj)
			if (can_put(fl, &fl->token, &fl->map, &pm))
				check_sum(fl->templmap.content, &fl->token, &pm, &fl->answ);
	}
	if (fl->answ.sum < ON * 3)
	{
		del_all(fl);
		ft_printf("%d %d\n", fl->answ.row, fl->answ.colum);
		return (1);
	}
	return (0);
}
