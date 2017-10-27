/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 12:06:10 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_all(t_data *data, t_figure *joueur)
{
	joueur->x = 0;
	joueur->y = 0;
	data->player_y = 0;
	free_array(data->figure, data->f_h);
	clear_map(data->map, data->m_h);
	data->f_h = 0;
	data->f_w = 0;
}

void	clear_map(char **arr, int size)
{
	int i;

	i = 0;
	while (i++ < size)
	{
		ft_strdel(arr);
		arr++;
	}
}

void	free_array(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
