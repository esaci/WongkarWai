#include "../include/lib_wkw.h"

int main( void ){
	int h, w;
	WINDOW *stdscr;

	stdscr = initscr();				//Initialise la structure WINDOW et autres paramètres 
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, h, w);
	printf("h vaut %d et w %d\n", h, w);
	// WINDOW * win = newwin(nlines, ncols, y0, x0);
	// printw("Hello World");	//Écrit Hello World à l'endroit où le curseur logique est positionné
	// refresh();				//Rafraîchit la fenêtre courante afin de voir le message apparaître
	// getch();				//On attend que l'utilisateur appui sur une touche pour quitter
	endwin();				//Restaure les paramètres par défaut du terminal
	return (0);
}