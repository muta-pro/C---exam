/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brackets_rec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:54:03 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/25 15:31:58 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
/*helper: check if an opening and closing bracket match
stack = array used as a stack for opened brackets
top  = index of top element in stack (-1 means empty)
*/

int	is_matching(char open, char close)
{
	return ((open == '(' && close == ')')
		|| (open == '{' && close == '}')
		|| (open == '[' && close == ']'));
}

int	check_br(const char *str, int i, char *stack, int top)
{
	char	c;

	c = str[i];
	if (c == '\0')
		return (top == -1);
	if (c == '(' || c == '[' || c == '{')
	{
		stack[++top] = c;
		return (check_br(str, i + 1, stack, top));
	}
	if (c == ')' || c == ']' || c == '}')
	{
		if (top < 0 || !is_matching(stack[top], c))
			return (0);
		return (check_br(str, i + 1, stack, top - 1));
	}
	return (check_br(str, i + 1, stack, top));
}

int	main(int argc, char **argv)
{
	char	stack[1024];
	int	i = 1;

	if (argc < 2)
		printf("\n");
	while (i < argc)
	{
		if (check_br(argv[i], 0, stack, -1))
			printf("ok\n");
		else
			printf("not\n");
		i++;
	}
	return (0);
}
