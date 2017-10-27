/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:31:49 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	prepare_positions(t_data *data)
{
	data->cnt = 0;
	data->first_go = 1;
	data->player_y = 0;
	data->player_x = 0;
	data->cnt = 0;
}

void	insert_figure(t_figure *joueur, int y, int x)
{
	joueur->put_figure = 1;
	ft_printf("%d %d\n", y, x);
}

int		main(void)
{
	t_data		data;
	t_figure	joueur;
	char		*line;

	prepare_positions(&data);
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$", 3) == 0)
			get_player(&joueur, &data, line);
		else if (ft_strncmp(line, "Plateau", 2) == 0)
		{
			if (data.cnt == 0)
				get_map_size(&data, line);
			ft_create_map(&data, line);
		}
		else if (ft_strncmp(line, "Piece", 2) == 0)
		{
			get_figure_size(&data, line);
			figure_stuff(&data, line, &joueur);
		}
		free(line);
	}
	free(line);
	return (0);
}
