/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/25 07:11:59 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static void	print_rows(int *board, int n)
{
	int	col;

	col = 0;
	while (col < n)
	{
		printf("%d", board[col]);
		col++;
	}
	printf("\n");
}

int	is_safe(int *board, int x, int y)
{
	int	dx;
	int	dy;
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == y)
			return (0);
		dx = x - i;
		dy = y - board[i];
		if (dx == dy || dx == -dy)
			return (0);
		i++;
	}
	return (1);
}

static void	put_queen_xy(int *board, int n, int x, int y)
{
	if (x == n)
	{
		print_rows(board, n);
		return ;
	}
	while (y < n)
	{
		if (is_safe(board, x, y))
		{
			board[x] = y;
			put_queen_xy(board, n, x + 1, 0);
			board[x] = -1;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	*board;
	int	n;

	if (argc != 2)
		return (0);
	n = atoi(argv[1]);
	if (n < 0)
		return (0);
	board = malloc(sizeof(int) * n);
	if (!board)
		return (1);
	i = 0;
	put_queen_xy(board, n, 0, 0);
	free(board);
	return (0);
}
