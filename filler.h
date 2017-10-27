/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/25 14:18:14 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_data
{
	int		m_h;
	int		m_w;
	int		first_go;
	int		his_y;
	int		player_y;
	int		player_x;
	int		f_h;
	int		f_w;
	int		cnt;
	char	competitor;
	char	**map;
	char	**figure;
}				t_data;

typedef struct	s_figure
{
	int		x;
	int		y;
	int		my_y;
	char	player;
	int		put_figure;
}				t_figure;

void			prepare_positions(t_data *data);

void			get_player(t_figure *joueur, t_data *data, char *line);
void			get_map_size(t_data *data, char *line);
void			get_figure_size(t_data *data, char *line);
int				ft_strchar(char *str, char c);
void			ft_create_map(t_data *data, char *line);
void			ft_create_figure(t_data *data, char *line);
void			figure_stuff(t_data *data, char *line, t_figure *joueur);

void			ft_filler(t_data *data, t_figure *joueur);
void			get_start_point(t_data *data, t_figure *joueur);

void			make_l_block(t_data *data, t_figure *joueur);
void			go_vertical_top(t_data *data, t_figure *joueur);
void			go_vertical_bottom(t_data *data, t_figure *joueur);
void			go_horizontal_top(t_data *data, t_figure *joueur);
void			go_horizontal_bottom(t_data *data, t_figure *joueur);

void			find_top_player(t_data *data, t_figure *joueur);
void			find_bottom_player(t_data *data, t_figure *joueur);
int				find_left_player(t_data *data, t_figure *joueur);
int				find_right_player(t_data *data, t_figure *joueur);

void			fill_left_side(t_data *data, t_figure *joueur);
void			fill_right_side(t_data *data, t_figure *joueur);
void			cover_from_bottom(t_data *data, t_figure *joueur);
void			cover_from_top(t_data *data, t_figure *joueur);

int				test_stuff(t_data *data, t_figure *joueur);
int				boundary_t(t_data data, t_figure joueur);
int				pos_t(t_data data, t_figure joueur);
void			insert_figure(t_figure *joueur, int y, int x);
void			free_all(t_data *data, t_figure *joueur);
void			free_array(char **arr, int size);
void			clear_map(char **arr, int size);

#endif
