#include "wongkarwai.h"

int	d_double_move(t_game *game, int i, int j, int sensx, int sensy)
{
	if (sensx > 0 || sensy > 0)
	{
		if (sensx)
			write(2, "|tu viens de taper sur right\n", 30);
		else
			write(2, "|tu viens de taper sur haut\n", 29);
		game->values[i + sensy][j + sensx] = (game->values[i + sensy][j + sensx] << 1);
		game->values[i][j] = 0;
	}
	else
	{
		if (sensx)
			write(2, "|tu viens de taper sur left\n", 29);
		else
			write(2, "|tu viens de taper sur bas\n", 28);
		game->values[i][j] = (game->values[i][j] << 1);	
		game->values[i + sensy][j + sensx] = 0;
	}
	game->empty_cases++;
	return(1);
}

int d_single_move(t_game *game, int i, int j, int sensx, int sensy)
{
	if (game->values[i][j] && !(game->values[i + sensy][j + sensx]))
	{
		if (sensx > 0 || sensy > 0)
		{
			if (sensx)
				write(2, "+tu viens de taper sur right\n", 30);
			else
				write(2, "+tu viens de taper sur haut\n", 29);
			game->values[i + sensy][j + sensx] = game->values[i][j];
			game->values[i][j] = 0;
			return (1);
		}
	}
	if (game->values[i + sensy][j + sensx] && !game->values[i][j])
	{
		if (sensx < 0 || sensy < 0)
		{
			if (sensx)
			{
				write(2, "+tu viens de taper sur left\n", 29);
				dprintf(2, "On est a la combinaison (%d , %d)\n", i, j);
				game->values[i][j] = game->values[i + sensy][j + sensx];
				game->values[i + sensy][j + sensx] = 0;
			}
			else
			{
				write(2, "+tu viens de taper sur bas\n", 28);
				game->values[i][j] = game->values[i + sensy][j + sensx];
				game->values[i + sensy][j + sensx] = 0;
			}
			// game->values[i][j] = game->values[i + sensy][j + sensx];
			// game->values[i + sensy][j + sensx] = 0;
			return (1);
		}
	}
	return (0);
}
