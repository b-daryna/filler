/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:37:55 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map_size(t_data *data, char *line)
{
	int i;

	i = 0;
	data->cnt = 1;
	while (ft_isalpha(line[i]))
		i++;
	data->m_h = ft_atoi(line + i);
	data->m_w = ft_atoi(line + i + ft_intsize(data->m_h) + 1);
	if (!(data->map = (char**)malloc(sizeof(char*) * (data->m_h + 1))))
		return ;
}

void	get_figure_size(t_data *data, char *line)
{
	int i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	data->f_h = ft_atoi(line + i);
	data->f_w = ft_atoi(line + i + ft_intsize(data->f_h) + 1);
	if (!(data->figure = (char**)malloc(sizeof(char*) * (data->f_h + 1))))
		return ;
}

void	ft_create_map(t_data *data, char *line)
{
	int i;

	i = 0;
	while (i < data->m_h && get_next_line(0, &line))
	{
		if (ft_strchar(line, '.') || ft_strchar(line, 'X') ||\
				ft_strchar(line, 'O'))
		{
			data->map[i] = ft_strdup(line + 4);
			i++;
		}
		free(line);
	}
	data->map[i] = 0;
}

void	figure_stuff(t_data *data, char *line, t_figure *joueur)
{
	ft_create_figure(data, line);
	ft_filler(data, joueur);
	free_all(data, joueur);
}

void	ft_create_figure(t_data *data, char *line)
{
	int i;

	i = 0;
	while (i < data->f_h && get_next_line(0, &line) != 0)
	{
		data->figure[i] = ft_strdup(line);
		free(line);
		i++;
	}
	data->figure[i] = 0;
}
