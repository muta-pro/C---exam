/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/18 09:11:46 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
	char temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *str, int l ,int r)
{
	int i;

	i = l;
	if (l == r)
	{
		printf("%s\n", str);
		return ;
	}
	while (i <= r)
	{
		swap((str + l), (str + i));
		permute(str, l + 1, r);
		swap((str + l), (str + i));
		i++;
	}
}

int main()
{
	char str[] = "ABC";
	int n;

	n = strlen(str);
	permute(str, 0, n - 1);
	return (0);
}