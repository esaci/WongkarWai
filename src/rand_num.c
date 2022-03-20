/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:50:20 by cdefonte          #+#    #+#             */
/*   Updated: 2022/03/19 17:38:57 by cdefonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wongkarwai.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Return a random value between 0 and max-1 */
int	ft_get_randpos(int max)
{
	int		rd;
	time_t	sec;

	sec = time(NULL);
	srand(sec);
	rd = rand();
	return (rd % max);
}

int	ft_get_randnum(void)
{
	int		rd;
	time_t	sec;

	sec = time(NULL);
	srand(sec);
	rd = rand();
	if (rd % 3 == 0)
		rd = 4;
	else
		rd = 2;
	return (rd);
}
