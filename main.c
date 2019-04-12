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

void		loop_infinity(t_filler *filler)
{
	char	*line;

	while (ft_gnl(0, &line) > -1)
	{
		if (ft_strnstr(line, "Plateau ", 8))
			read_map(line, &filler->map);
		if (ft_strnstr(line, "Piece ", 6))
		{
			read_token(line, &filler->token);
			teplo_carta(&filler->map, &filler->templmap, &filler->play);
			if (place_token_map(filler) == 0)
			{
				ft_printf("0 0\n");
				del_heat(filler, filler->templmap.content, (int)filler->map.y);
				exit(EXIT_SUCCESS);
			}
		}
	}
}

int			main(void)
{
	char		*line;
	t_filler	filler;

	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	if (ft_gnl(0, &line) && line && ft_strnstr(line, "$$$ exec p", 10))
	{
		if (ft_strchr(line, '1'))
			filler.play.i = 'O';
		else if (ft_strchr(line, '2'))
			filler.play.i = 'X';
		filler.play.enemy = ((filler.play.i == 'O') ? ('X') : ('O'));
		line != NULL ? free(line) : 0;
		loop_infinity(&filler);
	}
	return (0);
}
