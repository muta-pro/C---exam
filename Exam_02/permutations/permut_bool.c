/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permut_bool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:15:26 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/21 10:27:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	permute_bool_rec(const char *str, int n, int pos, int used[], char out[])
{
	int	i;

	if (pos == n)
	{
		out[n] = '\0';
		printf("%s\n", out);
		return ;
	}
	i = 0;
	while (i < n)
	{
		if (!used[i])
		{
			used[i] = 1;
			out[pos] = str[i];
			permute_bool_rec(str, n, pos + 1, used, out);
			used[i] = 0;
		}
		i++;
	}
}

int	main()
{
	const char	str[] = "abc";
	int			used[3] = {0, 0, 0};
	char		out[4];

	permute_bool_rec(str, 3, 0, used, out);
	return (0);
}

//backtracking pattern

//void backtrack(State state, int step)
//{
//	if (finish)
//	{
//		process_solution(state);
//		return ;
//	}
//	for each choice c from valid_choice(state, step)
//	{
//		apply_choice(state, c);
//		backtrack(state, step + 1);
//		undo_choice(state, c);
//	}
//}