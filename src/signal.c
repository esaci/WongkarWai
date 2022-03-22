#include "wongkarwai.h"

void	handler_game(int num)
{
	resetty();
	endwin();
	exit(num);
}

void	signal_game(void){
	signal(SIGINT, handler_game);
	signal(SIGQUIT, handler_game);
	signal(SIGTERM, handler_game);
}