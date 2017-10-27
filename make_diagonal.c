/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_diagonal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:34:25 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	go_vertical_top(t_data *data, t_figure *joueur)
{
	joueur->y = 0;
	while (joueur->y < data->m_h)
	{
		joueur->x = 0;
		while (joueur->x < data->m_w)
		{
			if (test_stuff(data, joueur))
				return ;
			joueur->x++;
		}
		joueur->y++;
	}
}

void	go_vertical_bottom(t_data *data, t_figure *joueur)
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

void	go_horizontal_bottom(t_data *data, t_figure *joueur)
{
	joueur->y = data->m_h - 1;
	while (joueur->y >= 0)
	{
		joueur->x = 0;
		while (joueur->x < data->m_w)
		{
			if (test_stuff(data, joueur))
				return ;
			joueur->x++;
		}
		joueur->y--;
	}
}

void	go_horizontal_top(t_data *data, t_figure *joueur)
{
	joueur->y = 0;
	while (joueur->y < data->m_h)
	{
		joueur->x = data->m_w - 1;
		while (joueur->x >= 0)
		{
			if (test_stuff(data, joueur))
				return ;
			joueur->x--;
		}
		joueur->y++;
	}
}
