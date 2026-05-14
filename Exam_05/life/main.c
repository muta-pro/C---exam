/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:52:09 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/14 20:27:19 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

char	**alloc_board(int w, int h)
{
	char	**board;
	int		i;
	int		j;

	board = calloc(h, sizeof(char *));
	if (!board)
		return (NULL);
	i = 0;
	while (i < h)
	{
		board[i] = malloc(w);
		if (!board[i])
		{
			while (--i >= 0)
				free(board[i]);
			free(board);
			return (NULL);
		}
		j = 0;
		while (j < w)
			board[i][j++] = ' ';
		i++;
	}
	return (board);
}

void	free_board(t_life *g)
{

}

int	main(int arc, char *argv[])
{
	t_life	g;
	int		iter;
	int		i;

	if (arc != 4)
		return (1);
	g.w = atoi(argv[1]);
	g.h = atoi(argv[2]);
	iter = atoi(argv[3]);
	if (g.h <= 0 || g.w <= 0 || iter <= 0)
		return (1);
	g.board = alloc_board(g.w, g.h);
	if (!g.board)
		return (1);
	fill_board(&g);
	i = 0;
	while (i++ < iter)
	{
		if (next_gen(&g) == -1)
		{
			free_board(g.board, g.h);
			return (1);
		}
	}
	printboard(&g);
	free_board(g.board, g.h);
	return (0);
}
