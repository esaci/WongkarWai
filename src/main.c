/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:23:34 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/19 19:54:51 by cdefonte         ###   ########.fr       */
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

void	ft_print_tab(t_game game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < game.board_size)
	{
		y = 0;
		while (y < game.board_size)
		{
			printf("tab[%d][%d] = %d\n", x, y, game.values[x][y]);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	int		inputch;
	int		board_size; // 4x4 ou 5x5=bonus
	t_game	game;

	if (argc > 1)
		board_size = ft_atoi(argv[1]);
	else
		board_size = 4;
	// ATTENTION si size terminal insuffisante ...
	ft_init_game(&game, board_size);
	if (game.width < 20 || game.height < 20)
	{
		endwin();
		return (ft_putstr_fd("Terminal is too small\n", 2), 1);
	}
	ft_call_options();
	inputch = -1;
	ft_print_boxes(&game);
	while (inputch != 27)
	{
		inputch = getch();
		if (inputch == KEY_RESIZE)
		{
			getmaxyx(stdscr, game.height, game.width);
			clear();
			ft_print_boxes(&game);
		}
		else if (inputch == KEY_LEFT)
		{
			// CALCUL ce qui se passe et modifie le game->values
			write(2, "LEFT\n", 5);
			make_move(&game, 0, -1);
		}
		else if (inputch == KEY_RIGHT)
		{
			write(2, "RIGHT\n", 6);
			make_move(&game, 0, 1);
		}
		else if (inputch == KEY_DOWN)
		{
			write(2, "DOWN\n", 5);
			make_move(&game, -1, 0);
		}
		else if (inputch == KEY_UP)
		{
			write(2, "UP\n", 5);
			make_move(&game, 1, 0);
		}
	}
	endwin();
//	ft_print_tab(game);
//	ft_fill_rand_num(&game);
//	printf("dSDSDSDSDSDSDSDSD\n");
//	ft_print_tab(game);
	return (0);
}
