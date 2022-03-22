#include "wongkarwai.h"


void	init_flag2(int flag2[5])
{
	for (int i = 0; i < 5; i++)
		flag2[i] = -1;
}

void	boucle_descendante(t_game *game, int sensy, int sensx)
{
	int	flag = 0;
	int	flag2[6];

	
	while (d_mov_single(game, sensy, sensx))
		flag++;
	init_flag2(flag2);
	for (int i = (sensy > 0 ? game->board_size - 2 : game->board_size - 1), j; i >= (sensy >= 0 ? 0 : 1); i--)
	{
		for (j = (sensx > 0 ? game->board_size - 2: game->board_size - 1); j >= (sensx >= 0 ? 0 : 1); j--)
		{
			if (flag2[i] == j)
				flag2[i] = -1;
			else if (game->values[i][j] && game->values[i + sensy][j + sensx] == game->values[i][j])
			{
				if (double_move(game, i, j, sensx, sensy))
				{
					if (sensx)
						j--;
					else
						flag2[i + sensy] = j + sensx;
					++flag;
				}
			}
		}
	}
	while (d_mov_single(game, sensy, sensx))
		flag++;
	if (flag)
		ft_fill_rand_num(game);
}

void boucle_ascendante(t_game *game, int sensy, int sensx)
{
	int	flag = 0;
	int	flag2[6];
	

	while (a_mov_single(game, sensy, sensx))
		flag++;
	init_flag2(flag2);
	for (int i = (sensy >= 0 ? 0 : 1), j; i < (sensy > 0 ? game->board_size - 1 : game->board_size ); i++)
	{
		for (j = (sensx >= 0 ? 0 : 1); j < (sensx > 0 ? game->board_size - 1: game->board_size); j++)
		{
			if (flag2[i] == j)
				flag2[i] = -1;
			else if (game->values[i][j] && game->values[i + sensy][j + sensx] == game->values[i][j])
			{
				if (double_move(game, i, j, sensx, sensy))
				{
					if (sensx)
						j++;
					else
						flag2[i + sensy] = j + sensx;
					++flag;
				}
			}
		}
	}
	while (a_mov_single(game, sensy, sensx))
		flag++;
	if (flag)
		ft_fill_rand_num(game);
}

int	test_move(t_game *game, int sensy, int	sensx)
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
	if (sensx < 0 || sensy < 0)
		boucle_descendante(game, sensy, sensx);
	else
		boucle_ascendante(game, sensy, sensx);
	return (0);
}

int	ft_check_loose(t_game *game)
{
	int	tmp[5][5];
	int	continueyes;
	
	continueyes = 0;
	for (int i = 0, j = 0; i < game->board_size; i++)
	{
		for (j = 0; j < game->board_size; j++)
			tmp[i][j] = game->values[i][j];
	}
	test_move(game, 0, -1);
	test_move(game, 0, 1);
	test_move(game, 1, 0);
	test_move(game, -1, 0);
	for (int i = 0, j = 0; i < game->board_size; i++)
	{
		for (j = 0; j < game->board_size; j++)
		{
			if (tmp[i][j] != game->values[i][j])
				continueyes = 1;
			game->values[i][j] = tmp[i][j];
		}
	}
	if (continueyes == 0 && game->victory != 1)
		game->victory = -1; // LOOSE
	else if (game->victory == 1 && continueyes == 0)
		game->victory = -2;
	return (0);
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
	if (sensx < 0 || sensy < 0)
		boucle_descendante(game, sensy, sensx);
	else
		boucle_ascendante(game, sensy, sensx);
	ft_print_boxes(game);
	if (game->empty_cases == 0)
		ft_check_loose(game);
	return (0);
}
