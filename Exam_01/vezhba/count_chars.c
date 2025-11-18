/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:23:53 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/18 15:53:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//count chars
// int	main(int argc, char *argv[])
// {
// 	char	*str;
// 	int		i;
// 	int		add;

// 	if (argc != 2)
// 		return (1);
// 	str = argv[1];
// 	i = 0;
// 	add = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 'a')
// 			add++;
// 		i++;
// 	}
// 	printf("%d", add);
// 	return (0);
// }
//count parenthesis
// int	main(int argc, char *argv[])
// {
// 	char	*str;
// 	int		i;
// 	int		add;

// 	if (argc != 2)
// 		return (1);
// 	str = argv[1];
// 	i = 0;
// 	add = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '(' || str[i] == ')')
// 			add++;
// 		i++;
// 	}
// 	printf("%d", add);
// 	return (0);
// }
//is parenthesis
int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc != 2)
		return (1);
	str = argv[1];
	i = 0;
	while (str[i])
	{
		if (str[i] != '(' && str[i] != ')')
			return (0);
		i++;
	}
	printf("contains only ()");
	return (0);
}

//count characters in a string using recursion

//count how many '(' are in the string using recursion