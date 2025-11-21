/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/21 11:38:59 by imutavdz         ###   ########.fr       */
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
		printf("%d\n", board[i]);
		i++;
	}
	printf("\n");
}
int	is_safe(int *board, int col, int row)
{
	int	prev_row;
	int	i;
	int	dist_x;
	int	dist_y;

	i = 0;
	while (i < col)
	{
		prev_row = board[i];
		if (prev_row == row)
			return (0);
		dist_x = col - i;
		dist_y = row - prev_row;
		if (dist_y == -dist_x)
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
