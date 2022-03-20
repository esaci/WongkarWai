/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wongkarwai.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:24:48 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/19 19:44:02 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONGKARWAI_H
# define WONGKARWAI_H

# include "wongkarwai.h"
# include <ncurses.h>
# include <curses.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef enum e_const {WIN_VALUE = 2048}t_const;

typedef struct s_empty_pos{
	int		x;
	int		y;
}				t_empty_pos;

typedef struct s_game{
	WINDOW	*win;
	int		width;
	int		height;
	int		board_size;
	int		values[5][5];
	int		empty_cases;
	t_empty_pos	empty_xy[25];
}				t_game;

void	temp_fill_table(t_game *game);

int		ft_get_randnum(void);
int		ft_get_randpos(int max);
int		put_image(t_game *game);
int		make_move(t_game *game, int sensx, int sensy);
void	ft_fill_rand_num(t_game *game);
int		ft_print_boxes(t_game *game);
int		single_move(t_game *game, int i, int j, int sensx, int sensy);
int		double_move(t_game *game, int i, int j, int sensx, int sensy);
int		d_single_move(t_game *game, int i, int j, int sensx, int sensy);
int		d_double_move(t_game *game, int i, int j, int sensx, int sensy);
#endif
