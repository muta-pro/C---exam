/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vezba.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:02:38 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/25 14:53:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

int	is_matching(char open, char close)
{
	return ((open == '(' && close == ')')
		|| (open == '{' && close == '}')
		|| (open == '[' && close == ']'));
}

int check_brackets(char *s, int i, int len, char *stack, int top)
{
	char c;

	c = s[i];

	if (i == len)
		return (top == -1);
	if (c == '(' || c == '[' || c == '{')
	{
		if (top == MAX_LEN - 1)
			return (0);
		stack[++top] = c;
		return (check_brackets(s, i + 1, len, stack, top));
	}
	if (c == ')' || c == ']' || c == '}')
	{
		if (top < 0 || !is_matching(stack[top], c))
			return (0);
		top--;
		return (check_brackets(s, i + 1, len, stack, top));
	}
	return (check_brackets(s, i + 1, len, stack, top));
}

int	main(int argc, char **argv)
{
	char	stack[MAX_LEN];
	int		i;
	int		len;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		len = (int)strlen(argv[i]);
		if (check_brackets(argv[i], 0, len, stack, 0))
			printf("OK\n");
		else
			printf("not\n");
		i++;
	}
	return (0);
}
