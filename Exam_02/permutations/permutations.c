/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:58:39 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/18 15:52:51 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void	swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	permute(char *str, int l, int r)
{
	int	i;

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

int	main()
{
	char	str[] = "ABC";
	int		n;

	n = strlen(str);
	permute(str, 0, n - 1);
	return (0);
}

// #include <unistd.h>

// // print n chars and a newline
// void	print_str(char *buf, int n)
// {
// 	write(1, buf, n);
// 	write(1, "\n", 1);
// }

// // generate all binary strings of length n
// void	gen_binary(int n, int i, char *buf)
// {
// 	if (i == n)
// 	{
// 		print_str(buf, n);
// 		return ;
// 	}
// 	buf[i] = '0';
// 	gen_binary(n, i + 1, buf);
// 	buf[i] = '1';
// 	gen_binary(n, i + 1, buf);
// }

// int	main(void)
// {
// 	int		n = 3;
// 	char	buf[3];

// 	gen_binary(n, 0, buf);
// 	return (0);
// }
