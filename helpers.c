/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:30:30 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_figure *joueur, t_data *data, char *line)
{
	if (ft_strstr(line, "p1"))
	{
		joueur->player = 'O';
		data->competitor = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		joueur->player = 'X';
		data->competitor = 'O';
	}
}

void	get_start_point(t_data *data, t_figure *joueur)
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
				joueur->my_y = i;
			else if (data->map[i][j] == data->competitor)
				data->his_y = i;
			data->first_go = 0;
			j++;
		}
		i++;
	}
}

int		ft_strchar(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}
