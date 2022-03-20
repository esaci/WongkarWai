/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:23:34 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/19 10:32:08 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wongkarwai.h"

int	main(void)
{
	int		x, h, w;
	WINDOW	*win;

	win = initscr();
	getmaxyx(stdscr, h, w);
	intrflush(stdscr, FALSE);
	// keypad(stdscr, TRUE); //permet d'avoir les keypads
	cbreak(); //permet au terminal de voir ctr + D + C etc. Plus besoin de enter, inverse de raw
	noecho(); //empeche getch etc de print ler contenu
	printw("2048 GAME- Taille Hauteur = %d | Taille largeur = %d\n", h, w);
	refresh();
	for (int i = 0, j; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			// if (i == h % 4 || j w % 4)
			mvprintw(i, j, "-");
		}
		printw("\n");
	}
	// x = -1;
	// while (x != 27)
	// {
		// x = getch();
		// printw("your input = %d\n", x);
		// refresh();
	// }
	while (1)
		x = getch();
	endwin();
	return (0);
	(void)x;
}
