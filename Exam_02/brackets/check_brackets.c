/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brackets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/21 00:08:39 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*STACK-BASED balanced parentheses check
Every time we see an opening bracket, we push it on the stack.
Every time we see a closing bracket, we:
Check if the stack is not empty.
Check if the top of the stack is the corresponding opening bracket.
If yes → pop it.
If no → invalid.
At the end, stack must be empty → all brackets matched.
Invariant (the “always true” rule)
While scanning the string:
The stack always contains exactly the opening brackets
 we have seen and not yet closed, in correct nesting order.
If you ever break that invariant 
(e.g. closing bracket that doesn’t match, 
or trying to close when stack is empty),
 you return error.*/
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
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if ((top == -1) || (!is_matching(stack[top], s[i])))
				return (0);
			top--;
		}
		i++;
	}
	return (top == -1); //valid str
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
