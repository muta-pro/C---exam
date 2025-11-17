/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parentheses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:02:08 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/18 00:18:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
check if the string is balanced having only ( ) 
algo to check balanced parentheses
*/
#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000
//loop
// int	main(int argc, char *argv[])
// {
// 	char	*str;
// 	int		i;
// 	int		calc;

// 	if (argc != 2)
// 		return (1);
// 	i = 0;
// 	calc = 0;
// 	str = argv[1];
// 	while (str[i])
// 	{
// 		if (str[i] == '(')
// 			calc++;
// 		else if (str[i] == ')')
// 		{
// 			if (calc > 0)
// 				calc--;
// 			else
// 				return (1);
// 		}
// 		i++;
// 	}
// 	if (calc != 0)
// 		return (1);
// 	return (0);
// }

// //recursion
// int	is_balanced(const char *str, int i, int calc)
// {
// 	if (calc < 0)
// 		return (0);
// 	if (str[i] == '\0')
// 		return (calc == 0);
// 	if (str[i] == '(')
// 		return (is_balanced(str, i + 1, calc + 1));
// 	else if (str[i] == ')')
// 		return (is_balanced(str, i + 1, calc - 1));
// 	else
// 		return (is_balanced(str, i + 1, calc));
// }

// int	main(int argc, char *argv[])
// {
// 	const char	*str;

// 	if (argc != 2)
// 		return (1);
// 	str = argv[1];
// 	if (is_balanced(str, 0, 0))
// 		printf("ok");
// 	else
// 		printf("not");
// 	return (0);
// }
// //recursion finding pairs and guarantees nested structure
// //use of substrings / split version

// int	is_bal_paired(char *str, int i, int len)
// {
// 	int	calc;
// 	int	j;

// 	if (i == len)
// 		return (1);
// 	if (str[i] == '(')
// 	{
// 		calc = 1;
// 		j = i + 1;
// 		while (j < len && calc > 0)
// 		{
// 			if (str[j] == '(')
// 				calc++;
// 			else if (str[j] == ')')
// 				calc--;
// 			j++;
// 		}
// 		if (calc != 0)
// 			return (0);
// 		return (is_balanced(str, i + 1, j - 1) && is_balanced(str, j, len));
// 	}
// 	return (is_balanced(str, i + 1, len));
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 		return (1);
// 	if (is_balanced(argv[1], 0, strlen(argv[1])))
// 		printf("ok");
// 	else
// 		printf("Err");
// 	return (0);
// }

//STACK-BASED balanced parentheses check
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
		else if (s[i] = '(' || s[i] == ']' || s[i] == '}')
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
