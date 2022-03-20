#include "wongkarwai.h"

void	boucle_descendante(t_game *game, int sensy, int sensx)
{
	int	flag = 0;
	
	write(2, "BOUCLE DESCENDANTE\n", 20);
	dprintf(2, "On a sensy/x qui vaut %d | %d\n", sensy, sensx);
	for (int i = (sensy > 0 ? game->board_size - 2 : game->board_size - 1), j; i >= (sensy >= 0 ? 0 : 1); i--)
	{
		for (j = (sensx > 0 ? game->board_size - 2: game->board_size - 1); j >= (sensx >= 0 ? 0 : 1); j--)
		{
			dprintf(2, "On est a la combinaison (%d , %d)\n", i, j);
			dprintf(2, "On a valuemtn/value suivante %d | %d\n", game->values[i][j], game->values[i + sensy][j + sensx]);
			if (game->values[i][j] && game->values[i + sensy][j + sensx] == game->values[i][j])
				flag += d_double_move(game, i, j, sensx, sensy);
			else if (!game->values[i][j] || !game->values[i + sensy][j + sensx])
				flag += d_single_move(game, i, j, sensx, sensy);
		}
	}
	if (flag)
	{
		// ft_fill_rand_num(game);
		ft_print_boxes(game);
		// refresh();
	}

}

void boucle_ascendante(t_game *game, int sensy, int sensx)
{
	int	flag = 0;

	write(2, "BOUCLE ASCENDANTE\n", 19);
	for (int i = (sensy >= 0 ? 0 : 1), j; i < (sensy > 0 ? game->board_size - 1 : game->board_size ); i++)
	{
		for (j = (sensx >= 0 ? 0 : 1); j < (sensx > 0 ? game->board_size - 1: game->board_size); j++)
		{
			if (game->values[i][j] && game->values[i + sensy][j + sensx] == game->values[i][j])
				flag += double_move(game, i, j, sensx, sensy);
			else if (!game->values[i][j] || !game->values[i + sensy][j + sensx])
				flag += single_move(game, i, j, sensx, sensy);
		}
	}
	if (flag)
	{
		// ft_fill_rand_num(game);
		ft_print_boxes(game);
		// refresh();
	}
}

// sensy positif = haut, sensx positif = droite
// faut les voir comme des bool, -1 ou +1
// ascendant fonctionne
int	make_move(t_game *game, int sensy, int	sensx)
{
	if (sensy && sensx)
	{
		make_move(game, 0, sensx);
		sensx = 0;
	}
	if (sensy < 0)
		sensy = -1;
	if (sensx < 0)
		sensx = -1;
	if (sensx < 0 || sensy > 0)
		boucle_descendante(game, sensy, sensx);
	else
		boucle_ascendante(game, sensy, sensx);
	return (0);
}