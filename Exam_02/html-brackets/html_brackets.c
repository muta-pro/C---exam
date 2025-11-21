/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   html_brackets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 07:44:41 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/21 12:43:53 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
pushing a string
strncmp - detect tags
struct or 2D array for stack*/
#include <string.h>
#include <stdio.h>

#define MAX_TAGS 100
#define MAX_LEN 50

int	ft_strcmp(const char *s1, const char *s2);

int	check_html(char *str)
{
	char	stack[MAX_TAGS][MAX_LEN];
	int		top;
	int		i;
	int		k;
	char	close_tag[MAX_LEN];

	top = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '/')
			{
				i += 2;
				k = 0;
				while (str[i] && str[i] != '>') //EXTRACT TAG
					close_tag[k++] = str[i++];
				close_tag[k] = '\0';
				if (top == -1)
					return (0);
				if (ft_strcmp(stack[top], close_tag) != 0)
					return (0);
				top--;
			}
			else
			{
				i++;
				if (top == MAX_TAGS - 1)
					return (0);
				top++;
				k = 0;
				while (str[i] && str[i] != '>')
					stack[top][k++] = str[i++]; //copy word into stack
				stack[top][k] = '\0';
			}
		}
		else
			i++;
	}
	return (top == -1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (check_html(argv[1]))
		printf("ok");
	else
		printf("not");
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
