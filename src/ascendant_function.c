#include "wongkarwai.h"

int	double_move(t_game *game, int i, int j, int sensx, int sensy)
{
	int same_in_a_row = 0;
	for(int temp = i + sensy, temp2 = j + sensx; temp >= 0 && temp2 >= 0 && temp < game->board_size && temp2 < game->board_size; temp += sensy, temp2 += sensx)
	{
		if (game->values[i][j] != game->values[temp][temp2])
			break;
		same_in_a_row++;
	}
	if (!(same_in_a_row % 2))
		return(0);
	game->values[i + sensy][j + sensx] = (game->values[i + sensy][j + sensx] << 1);
	if (game->values[i + sensy][j + sensx] >= WIN_VALUE && game->victory != -1)
		game->victory = 1;
	if (game->values[i + sensy][j + sensx] >= 2048)
		game->victory = -3;
	game->values[i][j] = 0;
	game->empty_cases++;
	return (1);
}

int single_move(t_game *game, int i, int j, int sensx, int sensy)
{
	if (game->values[i][j] && !(game->values[i + sensy][j + sensx]))
	{
			game->values[i + sensy][j + sensx] = game->values[i][j];
			game->values[i][j] = 0;
			return (1);
	}
	else if (game->values[i + sensy][j + sensx] && !game->values[i][j])
	{
			game->values[i][j] = game->values[i + sensy][j + sensx];
			game->values[i + sensy][j + sensx] = 0;
			return (1);
	}
	return (0);
}
int	a_mov_single(t_game *game, int sensy, int sensx)
{
	int flag = 0;

	for (int i = (sensy >= 0 ? 0 : 1), j; i < (sensy > 0 ? game->board_size - 1 : game->board_size ); i++)
		{
			for (j = (sensx >= 0 ? 0 : 1); j < (sensx > 0 ? game->board_size - 1: game->board_size); j++)
			{
				if (game->values[i][j] && !game->values[i + sensy][j + sensx])
					flag += single_move(game, i, j, sensx, sensy);
			}
		}
	return (flag);
}
