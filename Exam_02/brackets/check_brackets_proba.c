/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brackets_proba.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:32:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/20 21:17:29 by imutavdz         ###   ########.fr       */
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
	
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf(balanced(argv[1]) ? "OK" : "NOT");
	return (0);
}
