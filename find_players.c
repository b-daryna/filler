/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:29:53 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_left_player(t_data *data, t_figure *joueur)
{
	int i;
	int j;

	i = joueur->y;
	j = 0;
	while (j < data->m_w)
	{
		if (data->map[i][j] == joueur->player)
			return (j);
		j++;
	}
	return (data->m_w - 1);
}

int		find_right_player(t_data *data, t_figure *joueur)
{
	int i;
	int j;

	i = joueur->y;
	j = data->m_w - 1;
	while (j >= 0)
	{
		if (data->map[i][j] == joueur->player)
			return (j);
		j--;
	}
	return (0);
}

void	find_top_player(t_data *data, t_figure *joueur)
{
	int i;
	int j;

	i = 0;
	while (i < data->m_h)
	{
		j = 0;
		while (j < data->m_w)
		{
			if (data->map[i][j] == joueur->player)
			{
				data->player_y = i;
				data->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_bottom_player(t_data *data, t_figure *joueur)
{
	int i;
	int j;

	i = data->m_h - 1;
	while (i >= 0)
	{
		j = data->m_w - 1;
		while (j >= 0)
		{
			if (data->map[i][j] == joueur->player)
			{
				data->player_y = i;
				data->player_x = j;
				return ;
			}
			j--;
		}
		i--;
	}
}
