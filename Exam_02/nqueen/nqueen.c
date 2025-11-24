/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:35:03 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/24 18:49:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void	print_q(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == n - 1)
		{
			printf("%d\n", board[i]);
			return ;
		}
		printf("%d ", board[i]);
		i++;
	}
	printf("\n");
}

int	absolute(int x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}

bool	is_safe(int *board, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == y || absolute(i - x) == absolute(board[i] - y))
			return (false);
		i++;
	}
	return (true);
}

void	put_queen_xy(int *board, int n, int x, int y)
{
	if (x >= n)
	{
		print_q(board, n);
		return ;
	}
	if (y >= n)
		return ;
	if (is_safe(board, x, y))
	{
		board[x] = y;
		put_queen_xy(board, n, x + 1, 0);
		board[x] = -1;
		put_queen_xy(board, n, x, y + 1);
	}
	else
		put_queen_xy(board, n, x, y + 1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	if (n <= 3)
	{
		printf("\n");
		return (0);
	}
	int	board[n];
	i = 0;
	while (i < n)
	{
		board[i] = -1;
		i++;
	}
	put_queen_xy(board, n, 0, 0);
	return (0);
}
