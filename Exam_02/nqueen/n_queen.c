/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/24 18:24:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	print_solution(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		i++;
	}
	printf("\n\n");
}

int	is_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (abs(board[i] - row) == abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int n, int col)
{
	int	row;

	if (col == n)
	{
		print_solution(board, n);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, n, col + 1);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*board;

	if (argc != 2)
		return (0);
	n = atoi(argv[1]);
	if (n < 0)
		return (0);
	board = calloc(n, sizeof(int));
	if (!board)
		return (1);
	solve(board, n, 0);
	free(board);
	return (0);
}
