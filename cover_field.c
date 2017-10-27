/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 13:06:10 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cover_from_bottom(t_data *data, t_figure *joueur)
{
	joueur->y = data->m_h - 1;
	while (joueur->y >= 0)
	{
		joueur->x = data->m_w - 1;
		while (joueur->x >= 0)
		{
			if (test_stuff(data, joueur))
				return ;
			joueur->x--;
		}
		joueur->y--;
	}
}

void	cover_from_top(t_data *data, t_figure *joueur)
{
	joueur->y = 0;
	while (joueur->y < data->m_h)
	{
		joueur->x = 0;
		while (joueur->x < data->m_w)
		{
			if (boundary_t(*data, *joueur) && pos_t(*data, *joueur))
			{
				insert_figure(joueur, joueur->y, joueur->x);
				return ;
			}
			joueur->x++;
		}
		joueur->y++;
	}
}
