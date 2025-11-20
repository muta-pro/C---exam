/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:01:46 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/20 17:01:20 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}
int is_negative(char **str)
{
	if ((*str)[0] == '-')
	{
		(*str)++;
		return (1);
	}
	return (0);
}
int ft_strcmp(char *a, char *b)
{
	int a_len = ft_strlen(a);
	int b_len = ft_strlen(b);
	if (a_len != b_len)
		return (a_len - b_len);
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
void rec_add(char *a, char *b, int a_index, int b_index, int remain)
{
	int a_num;
	int b_num;
	if (a_index < 0 && b_index < 0 && remain == 0)
		return ;
	if (a_index >= 0)
		a_num = a[a_index] - '0';
	else
		a_num = 0;
	if (b_index >= 0)
		b_num = b[b_index] - '0';
	else
		b_num = 0;
	
	// printf("a_num = %d\n", a_num);
	// printf("b_num = %d\n", b_num);
	int sum = a_num + b_num + remain;
	int last_digit = sum % 10;
	int new_remain = sum / 10;
	// printf("sum = %d, last digit = %d, remain = %d\n", sum, last_digit, new_remain);
	rec_add(a, b, a_index - 1, b_index - 1, new_remain);
	ft_putchar(last_digit + '0');
}
void rec_sub(char *a, char *b, int a_index, int b_index, int borrow)
{
	int a_num;
	int b_num;
	if (a_index < 0 && b_index < 0 && borrow == 0)
		return ;
	if (a_index >= 0)
		a_num = a[a_index] - '0';
	else
		a_num = 0;
	if (b_index >= 0)
		b_num = b[b_index] - '0';
	else
		b_num = 0;
	int sub = a_num - b_num - borrow;
	borrow = 0;
	if (sub < 0)
	{
		sub += 10;
		borrow = 1;
	}
	rec_sub(a, b, a_index - 1, b_index - 1, borrow);
	ft_putchar(sub + '0');
}
int main(int argc, char **argv)
{
	// (void)argc;
	// (void)argv;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *a = argv[1];
	char *b = argv[2];
	// char *a = "-23";
	// char *b = "110";
	int a_neg = is_negative(&a);
	int b_neg = is_negative(&b);
	int a_len = ft_strlen(a);
	int b_len = ft_strlen(b);
	if (a_neg == b_neg)
	{
		if (a_neg == 1)
			ft_putchar('-');
		rec_add(a, b, a_len - 1, b_len - 1, 0);
	}
	else
	{
		int compare = ft_strcmp(a, b);
		if (compare == 0)
			ft_putchar('0');
		else if (compare > 0)
		{
			if (a_neg == 1)
				ft_putchar('-');
			rec_sub(a, b, a_len - 1, b_len - 1, 0);
		}
		else
		{
			if (b_neg == 1)
				ft_putchar('-');
			rec_sub(b, a, b_len - 1, a_len - 1, 0);
		}
	}
	write(1, "\n", 1);
	return (0);
}