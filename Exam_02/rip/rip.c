/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:01:30 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/23 18:34:27 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	count_removals(const char *s, int *left_rem, int *right_rem)
{
	int	open;
	int	i;

	open = 0;
	i = 0;
	*left_rem = 0;
	*right_rem = 0;
	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				(*right_rem)++;
		}
		i++;
	}
	*left_rem = open;
}

static void	backtrack(const char *s, int i, char *out,
	int left_rem, int right_rem, int still_open, int len)
{
	char	c;

	if (i == len)
	{
		if (left_rem == 0 && right_rem == 0 && still_open == 0)
		{
			out[len] = '\0';
			puts(out);
		}
		return ;
	}
	c = s[i];
	if (c == '(')
	{
		if (left_rem > 0)
		{
			out[i] = ' ';
			backtrack(s, i + 1, out, left_rem - 1, right_rem, still_open, len);
		}
		out[i] = '(';
		backtrack(s, i + 1, out, left_rem, right_rem, still_open + 1, len);
	}
	else if (c == ')')
	{
		if (right_rem > 0)
		{
			out[i] = ' ';
			backtrack(s, i + 1, out, left_rem, right_rem - 1, still_open, len);
		}
		if (still_open > 0)
		{
			out[i] = ')';
			backtrack(s, i + 1, out, left_rem, right_rem, still_open - 1, len);
		}
	}
	else
	{
		out[i] = c;
		backtrack(s, i + 1, out, left_rem, right_rem, still_open, len);
	}
}

int	main(int argc, char **argv)
{
	const char	*s;
	int			len;
	int			left_rem;
	int			right_rem;
	char		*out;

	if (argc != 2)
		return (1);
	s = argv[1];
	len = (int)strlen(s);
	out = malloc(len + 1);
	if (!out)
		return (1);
	count_removals(s, &left_rem, &right_rem);
	backtrack(s, 0, out, left_rem, right_rem, 0, len);
	free(out);
	return (0);
}
