/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:20:47 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/21 10:42:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*choose, explore, backtrack
pick and move
decision tree alg*/

#include <stdio.h>

void	powerset(char *str, char *subset, int start, int sub_len)
{
	int	i;

	subset[sub_len] = '\0';
	printf("%s", subset);
	i = start;
	while (str[i])
	{
		subset[sub_len] = str[i];
		powerset(str, subset, i + 1, sub_len + 1);
		i++;
	}
}

int	main()
{
	char	data[] = "ABC";
	char	buf[10];

	powerset(data, buf, 0, 0);
	return (0);
}
