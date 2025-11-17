/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorial.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:30:14 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/17 22:08:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
/* n! = n * (n-1)!
	0! = 1
recursive*/

int	fact(int n)
{
	if (n <= 1)
		return (1);
	return (n * fact(n - 1));
}

int	main(void)
{
	printf("%d\n", fact(5));
	return (0);
}
