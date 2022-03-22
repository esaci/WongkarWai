/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:38:25 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/20 16:42:16 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wongkarwai.h"

int	erase_number(t_game *game, int h, int w)
{
	w = w * (game->width /game->board_size);
	h = h * (game->height / game->board_size) + (game->height /game->board_size) / 2;
	for (int i = 0; i < (game->width /game->board_size); i++)
		mvprintw(h, w + i," ");
	return (0);
}

int	ft_nb_digit(int nb)
{
	int	res;
	int	x;

	x = nb;
	res = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x = x / 10;
		res++;
	}
	return (res);
}

int	put_number(t_game *game, int h, int w)
{
	int		nb_digit;
	int		posx;
	int		posy;

	nb_digit = ft_nb_digit(game->values[h][w]);
	posx = w * (game->width / game->board_size) + (game->width /game->board_size) / 2;
	posy = h * (game->height / game->board_size) + (game->height /game->board_size) / 2;
	mvprintw(posy, posx - nb_digit, "%d\n", game->values[h][w]);
	return (0);
}

int	put_image(t_game *game)
{
	for (int i = 0,j = 0; i < game->board_size; i++)
	{
		for (j = 0; j < game->board_size; j++)
		{
			erase_number(game, i, j);
			if (game->values[i][j] != 0)
				put_number(game, i, j);
		}
	}
	return (0);
}
