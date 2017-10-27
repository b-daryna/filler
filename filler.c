/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 15:18:50 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_filler(t_data *data, t_figure *joueur)
{
	joueur->put_figure = 0;
	if (data->first_go)
		get_start_point(data, joueur);
	make_l_block(data, joueur);
	if (!joueur->put_figure)
	{
		if (joueur->my_y > data->his_y)
			fill_left_side(data, joueur);
		else
			fill_right_side(data, joueur);
	}
	if (!joueur->put_figure)
	{
		if (joueur->my_y > data->his_y)
			cover_from_top(data, joueur);
		else
			cover_from_bottom(data, joueur);
	}
	if (!joueur->put_figure)
		insert_figure(joueur, -1, -1);
}

void	make_l_block(t_data *data, t_figure *joueur)
{
	if (joueur->my_y > data->his_y)
	{
		find_top_player(data, joueur);
		if (data->player_y && data->player_x)
			go_vertical_top(data, joueur);
		else
		{
			find_bottom_player(data, joueur);
			if (data->player_y < data->m_h - 1 && data->player_x < data->m_w - 1)
				go_horizontal_bottom(data, joueur);
		}
	}
	else
	{
		find_bottom_player(data, joueur);
		if (data->player_y < data->m_h - 1 && data->player_x < data->m_w - 1)
			go_vertical_bottom(data, joueur);
		else
		{
			find_top_player(data, joueur);
			if (data->player_y && data->player_x)
				go_horizontal_top(data, joueur);
		}
	}
}

void	fill_left_side(t_data *data, t_figure *joueur)
{
	int lim;

	joueur->y = 0;
	while (joueur->y < data->m_h)
	{
		joueur->x = 0;
		lim = find_left_player(data, joueur);
		while (joueur->x <= lim)
		{
			if (test_stuff(data, joueur))
				return ;
			joueur->x++;
		}
		joueur->y++;
	}
}

void	fill_right_side(t_data *data, t_figure *joueur)
{
	int lim;

	joueur->y = data->m_h - 1;
	while (joueur->y >= 0)
	{
		joueur->x = data->m_w - 1;
		lim = find_right_player(data, joueur);
		while (joueur->x >= lim)
		{
			if (test_stuff(data, joueur))
				return ;
			joueur->x--;
		}
		joueur->y--;
	}
}
