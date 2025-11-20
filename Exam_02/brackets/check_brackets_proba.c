/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brackets_proba.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:32:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/20 18:25:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX_LEN 1000

int	is_matching(char open, char close)
{
	return ((open == '(' && close == ')')
		|| (open == '{' && close == '}')
		|| (open == '[' && close == ']'));
}

int	balanced(char *s)
{
	char	stack[MAX_LEN];
	int		top;
	int		i;

	top = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			if (top == MAX_LEN - 1)
				return (0);
			stack[++top] = s[i];
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (top == -1 || !is_matching(stack[top], s[i]))
				return (0);
			top --;
		}
		i++;
	}
	return (top == -1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf(balanced(argv[1]) ? "OK" : "NOT");
	return (0);
}
