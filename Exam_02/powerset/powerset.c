/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:47:23 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/22 13:32:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Bytes Needed = {Size of the data type} \times {How many items you want}
INCLUDE / EXCLUDE DECISION
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_sub(int *sub, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d", sub[i]);
		if (i < len - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	solve(int *set, int set_len, int *subset,
	int sub_len, int idx, int curr_sum, int target)
{
	if (idx == set_len)
	{
		if (curr_sum == target)
			print_sub(subset, sub_len);
		return ;
	}
	subset[sub_len] = set[idx];
	solve(set, set_len, subset, sub_len + 1, idx + 1, curr_sum + set[idx], target);
	solve(set, set_len, subset, sub_len, idx + 1, curr_sum, target);
}

int	main(int argc, char **argv)
{
	int	target;
	int	*set;
	int	*subset_b;
	int	set_len;
	int	i;

	if (argc < 2)
		return (0);
	target = atoi(argv[1]);
	set_len = argc - 2;
	if (set_len < 0)
		set_len = 0;
	set = malloc(sizeof(int) * set_len);
	if (!set && set_len > 0)
		return (1);
	subset_b = malloc(sizeof(int) * set_len);
	if (!subset_b && set_len > 0)
	{
		free(set);
		return (1);
	}
	i = 0;
	while (i < set_len)
	{
		set[i] = atoi(argv[i + 2]);
		i++;
	}
	solve(set, set_len, subset_b, 0, 0, 0, target);
	free(set);
	free(subset_b);
	return (0);
}

