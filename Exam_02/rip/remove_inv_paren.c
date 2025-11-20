/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_inv_paren.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/21 00:00:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
BFS breadth-first search for minumum removals*/
/*
check the balance but removing parentheses to make it balanced
and check all valid results
with recursion and backtracking
generating all possible valid variations 
generate ALL valid possibilities by removing bad parentheses
 → this is a classic backtracking / DFS problem:

choose a char → keep or delete → recurse → prune invalid branches.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isValid(const char *s)
{
	int bal = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
		{
			bal--;
			if (bal < 0)
				return false;
		}
		i++;
	}
	return (bal == 0);
}
void count_excess(const char *s, int *left, int *right)
{
	int bal = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
		{
			if (bal > 0)
				bal--;
			else
				(*right)++;
		}
		i++;
	}
	*left = bal;
}
void remove_extra(char *s, int pos, int left, int right)
{
	if (left == 0 && right == 0)
	{
		if (isValid(s))
		{
			puts(s);
		}
		return;
	}
	int i = pos;
	while (s[i])
	{
		if (s[i] == '(' && left > 0)
		{
			char saved = s[i];
			s[i] = ' ';
			remove_extra(s, i + 1, left - 1, right);
			s[i] = saved;
		}
		else if (s[i] == ')' && right > 0)
		{
			char saved = s[i];
			s[i] = ' ';
			remove_extra(s, i + 1, left, right - 1);
			s[i] = saved;
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	char *str = argv[1];
	int left = 0;
	int right = 0;
	count_excess(str, &left, &right);
	remove_extra(str, 0, left, right);
	return 0;
}
