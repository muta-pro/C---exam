/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:05:35 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/16 20:14:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*focus on right to left with carry logic
 - add two positive equal-len numbers
 probem suddivision: 
 1. turn char into number ASCII math
 2. get carry & digit from the sum - use / and %
 3. build string backward - fill buf_str from the end
 */
char	*add(const char *a, const char *b)
{
	int		k;
	int		i;
	int		carry;
	int		len;
	char	*buf;
	int		digit1;
	int		digit2;
	int		sum;
	char	*result;

	len = strlen(a);
	buf = calloc(len + 2, sizeof(char));
	k = len;
	carry = 0;
	i = len - 1;
	while (i >= 0)
	{
		digit1 = a[i] - '0';
		digit2 = b[i] - '0';
		sum = digit1 + digit2 + carry;
		carry = sum / 10;
		i--;
		buf[k--] = sum % 10 + '0';
	}
	if (carry > 0)
		buf[k] = carry + '0';
	else
	{
		result = strdup(buf + 1);
		free(buf);
		return (result);
	}
	return (buf);
}

int	main(int argc, char *argv[])
{
	char	*sum;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
		return (1);
	}
	if (strlen(argv[1]) != strlen(argv[2]))
	{
		fprintf(stderr, "Error - numbers must be the same lenght\n");
		return (1);
	}
	sum = add(argv[1], argv[2]);
	printf("SUM = %s\n", sum);
	free(sum);
	return (0);
}
