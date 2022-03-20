/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:38:25 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/19 18:40:36 by cdefonte         ###   ########.fr       */
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

int	put_number(t_game *game, int h, int w)
{
	char	*tmp;

	erase_number(game, h, w);
	tmp = ft_itoa(game->values[h][w]);
	w = w * (game->width / game->board_size) + (game->width /game->board_size) / 2;
	h = h * (game->height / game->board_size) + (game->height /game->board_size) / 2;
	if (!tmp)
		exit(1);
	if (ft_strlen(tmp) == 1 && tmp[0] == '0')
		return (0);
	mvprintw(h, w - (ft_strlen(tmp) / 2), "%s\n", tmp);
	// refresh();
	return (0);
}

int	put_image(t_game *game)
{
	for (int i = 0,j = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			put_number(game, i, j);
	}
	return (0);
}

void	temp_fill_table(t_game *game)
{
	for (int i = 0,j = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			game->values[i][j] = 685;
		}
	}
	put_image(game);
}
