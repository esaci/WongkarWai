#include "wongkarwai.h"



int	d_mov_single(t_game *game, int sensy, int sensx)
{
	int	flag = 0;
	
	for (int i = (sensy > 0 ? game->board_size - 2 : game->board_size - 1), j; i >= (sensy >= 0 ? 0 : 1); i--)
	{
		for (j = (sensx > 0 ? game->board_size - 2: game->board_size - 1); j >= (sensx >= 0 ? 0 : 1); j--)
		{
			if (game->values[i][j] && !game->values[i + sensy][j + sensx])
					flag += single_move(game, i, j, sensx, sensy);
		}
	}
	return (flag);
}