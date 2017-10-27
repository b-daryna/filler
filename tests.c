/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:40:11 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		test_stuff(t_data *data, t_figure *joueur)
{
	if (boundary_t(*data, *joueur) && pos_t(*data, *joueur))
	{
		insert_figure(joueur, joueur->y, joueur->x);
		return (1);
	}
	return (0);
}

int		boundary_t(t_data data, t_figure joueur)
{
	if (joueur.y < 0 || joueur.x < 0)
		return (0);
	if (joueur.y + data.f_h > data.m_h)
		return (0);
	if (joueur.x + data.f_w > data.m_w)
		return (0);
	return (1);
}

int		pos_t(t_data data, t_figure joueur)
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < data.f_h)
	{
		j = 0;
		while (j < data.f_w)
		{
			if (data.figure[i][j] == '*')
			{
				if (data.map[joueur.y + i][joueur.x + j] == joueur.player)
					cnt++;
				if (cnt > 1 || (data.map[joueur.y + i][joueur.x + j] \
							!= '.' && data.map[joueur.y + i][joueur.x + j] \
							!= joueur.player))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (cnt);
}
