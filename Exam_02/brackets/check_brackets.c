/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brackets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/18 07:04:50 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//STACK-BASED balanced parentheses check
#include <stdio.h>

#define MAX_LEN 1000

int	is_matching(char open, char close)
{
	return ((open == '(' && close == ')')
		|| (open == '[' && close == ']')
		|| (open == '{' && close == '}'));
}

int	check_brackets(char *s)
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
		else if (s[i] == '(' || s[i] == ']' || s[i] == '}')
		{
			if (top == -1)
				return (0);
			if (!is_matching(stack[top], s[i]))
				return (0);
			top--;
		}
		i++;
	}
	return (top == -1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (check_brackets(argv[1]))
		printf("ok");
	else
		printf("Error");
	return (0);
}
