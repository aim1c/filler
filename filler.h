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

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include <stdio.h>
# include "libft.h"

# define ON 1000000
# define PLAYERS 2
# define DOT 1

typedef struct		s_filler_map
{
	char			**content;
	int 	       	y;
	int 			x;
	int				size;
}					t_f_map;

typedef struct		s_filler_gamers
{
	char			i;
	char			enemy;
}					t_f_players;

typedef struct		s_tepl
{
	int				**content;
	int				what_set;
	int				what_sub;
}					t_temrmap;

typedef struct		s_answ
{
	int				row;
	int				colum;
	int				sum;
}					t_answ;

typedef struct		s_boxx
{
	int				i;
	int				j;
	int				li;
	int				lj;
}					t_boxx;

typedef struct		s_sa
{
	int				size;
	int				count;
}					t_sa;

typedef struct		s_filler
{
	t_f_map			map;
	t_f_map			token;
	t_f_players		play;
	t_temrmap		templmap;
	t_answ			answ;
}					t_filler;

typedef struct		s_box
{
	int				row;
	int				elem;
	int				row_lim;
	int				elem_lim;
}					t_box;



void				teplo_carta(t_f_map *map, t_temrmap *t, t_f_players *play);
void				del_all(t_filler *fil);
int					place_token_map(t_filler *fill);
void				read_map(char *line, t_f_map *map);
void				read_token(char *line, t_f_map *token);
void				del_heat(t_filler *fil, int **heat, int li);

#endif
