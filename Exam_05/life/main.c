/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:52:09 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/15 14:44:30 by imutavdz         ###   ########.fr       */
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

void	free_board(char **board, int h)
{
	int	i;

	i = 0;
	while (i < h)
		free(board[i++]);
	free(board);
}

void	fill_board(t_life *g)
{
	char	c;
	int		row;
	int		col;
	int		draw;

	row = 0;
	col = 0;
	draw = 0;
	while (read(0, &c, 1) == 1)
	{
		if (c == 'w' && row > 0)
			row--;
		else if (c == 's' && row < g->h - 1)
			row++;
		else if (c == 'a' && col > 0)
			col--;
		else if (c == 'd' && col < g->w - 1)
			col++;
		else if (c == 'x')
			draw = !draw;
		else
			continue ;
		if (draw)
			g->board[row][col] = '0';
	}
}

int	count_neighbors(t_life *g, int row, int col)
{
	int	count;
	int	dr;
	int	dc;
	int	nr;
	int	nc;

	count = 0;
	dr = -1;
	while (dr <= 1)
	{
		dc = -1;
		while (dc <= 1)
		{
			if (dr != 0 || dc != 0)
			{
				nr = row + dr;
				nc = col + dc;
				if (nr >= 0 && nr < g->h && nc >= 0 && nc < g->w)
					if (g->board[nr][nc] == '0')
						count++;
			}
			dc++;
		}
		dr++;
	}
	return (count);
}

int	next_gen(t_life *g)
{
	char	**next;
	int		neighbors;
	int		i;
	int		j;

	next = alloc_board(g->w, g->h);
	if (!next)
		return (-1);
	i = 0;
	while (i < g->h)
	{
		j = 0;
		while (j < g->w)
		{
			neighbors = count_neighbors(g, i, j);
			if (g->board[i][j] == '0')
				next[i][j] = (neighbors == 2 || neighbors == 3) ? '0' : ' ';
			else
				next[i][j] = (neighbors == 3) ? '0' : ' ';
			j++;
		}
		i++;
	}
	free_board(g->board, g->h);
	g->board = next;
	return (0);
}

void	printboard(t_life *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->h)
	{
		j = 0;
		while (j < g->w)
			putchar(g->board[i][j++]);
		putchar('\n');
		i++;
	}
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
