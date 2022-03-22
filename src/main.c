/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:23:34 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/20 17:40:32 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wongkarwai.h"

void	ft_empty_xy(t_game *game)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (game->empty_cases == 0)
		return ;;
	while (x < game->board_size)
	{
		y = 0;
		while (y < game->board_size)
		{
			if (game->values[x][y] == 0)
			{
				game->empty_xy[i].x = x;
				game->empty_xy[i].y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

/* Retourne le nombre de cases vides(= 0) dans le tableau de values. */
int	ft_nb_empty(t_game *game)
{
	int		x;
	int		y;
	int		nb_empty;

	x = 0;
	y = 0;
	nb_empty = 0;
	if (game->empty_cases == 0)
		return (0);
	while (x < game->board_size)
	{
		y = 0;
		while (y < game->board_size)
		{
			if (game->values[x][y] == 0)
				nb_empty++;
			y++;
		}
		x++;
	}
	return (nb_empty);
}

/* Fill une case choisie au hasard, par 2 ou 4 choisit au hasad 
Du coup fait game->empty cases - 1*/
void	ft_fill_rand_num(t_game *game)
{
	int		rd_val;
	int		rd_x;
	int		rd_y;
	int		rd_index;

	if (game->empty_cases == 0)
		return ;;
	ft_empty_xy(game);
	rd_index = ft_get_randpos(game->empty_cases);
	rd_x = game->empty_xy[rd_index].x;
	rd_y = game->empty_xy[rd_index].y;
	rd_val = ft_get_randnum();
	game->values[rd_x][rd_y] = rd_val;
	--game->empty_cases;
}

/* Set a 0 tous les elements du int **values de game */
void	ft_init_tabval(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < game->board_size)
	{
		y = 0;
		while (y < game->board_size)
		{
			game->values[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	ft_init_game(t_game *game, int board_size)
{
	game->win = initscr();
	getmaxyx(stdscr, game->height, game->width);
	game->board_size = board_size;
	game->empty_cases = board_size * board_size;
	ft_init_tabval(game);
	ft_fill_rand_num(game);
	game->victory = -1;
	int	x = WIN_VALUE;
	if (!(x &(x-1)))
		game->victory = 0;
	return (0);
}

void	ft_call_options(void)
{
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE); //permet d'avoir les keypads
	cbreak(); //permet au terminal de voir ctr + D + C etc. Plus besoin de enter, inverse de raw
	noecho(); //empeche getch etc de print ler contenu
}

int	ft_print_boxes(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	put_image(game);
	while (x <= game->board_size)
	{
		mvvline(0, (game->width / game->board_size) * (x % (game->board_size + 1)), '|', game->height - (game->height % game->board_size));
		x++;
	}
	while (y <= game->board_size)
	{
		mvhline((game->height / game->board_size) * (y % (game->board_size + 1)), 0, '-', game->width - (game->width % game->board_size));
		y++;
	}
	refresh();
	return (0);
}

int	main(void)
{
	int		inputch;
	int		board_size;
	t_game	game;

	board_size = 4;
	savetty();
	signal_game();
	ft_init_game(&game, board_size);
	if (game.width < 20 || game.height < 20)
	{
		endwin();
		return (ft_putstr_fd("Terminal is too small\n", 2), 1);
	}
	ft_call_options();
	inputch = -1;
	ft_print_boxes(&game);
	while (game.victory >= 0 && inputch != 27)
	{
		inputch = getch();
		if (inputch == KEY_RESIZE)
		{
			getmaxyx(stdscr, game.height, game.width);
			clear();
			ft_print_boxes(&game);
		}
		else if (inputch == KEY_LEFT)
			make_move(&game, 0, -1);
		else if (inputch == KEY_RIGHT)
			make_move(&game, 0, 1);
		else if (inputch == KEY_DOWN)
			make_move(&game, 1, 0);
		else if (inputch == KEY_UP)
			make_move(&game, -1, 0);
		// else if (inputch == KEY_BACKSPACE)
		// {
			// game.values[0][0] = 16;
			// game.values[1][0] = 8;
			// game.values[2][0] = 4;
			// game.values[3][0] = 4;
			// ft_print_boxes(&game);
		// }
	}
	resetty();
	endwin();
	if (game.victory == -1)
		ft_putstr_fd("YOU LOSE\n", 1);
	if (game.victory == -2 || game.victory == 1)
		ft_putstr_fd("YOU WIN\n", 1);
	if (game.victory == -3)
		ft_putstr_fd("ULTIMATE WIN 2048!!!!!!!!!!!\n", 1);
	return (0);
}
