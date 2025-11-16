/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlproba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:21:50 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/12 14:31:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (&*s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	str_apped_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = ft_strlen(*s1);
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (s1)
	{
		ft_memcpy(tmp, *s1, size1);
		free(*s1);
	}
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	*s1 = tmp;
	return (1);
}

int	str_apped_str(char **s1, char *s2)
{
	return (str_apped_mem(s1, s2, ft_strlen(s2)));
}

char	*ft_memmove(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char		*line;
	char		*tmp;
	int			read_line;
	size_t		len_line;

	line = NULL;
	tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_apped_str(&line, b))
			return (NULL);
		read_line = read(fd, b, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(line);
			return (NULL);
		}
		b[read_line] = '\0';
		if (read_line == 0)
		{
			if (line && *line)
				return (line);
			free(line);
			return (NULL);
		}
		tmp = ft_strchr(b, '\n');
	}
	len_line = tmp - b + 1;
	if (!str_apped_mem(&line, b, len_line))
	{
		free(line);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1));
	b[ft_strlen(tmp + 1)] = '\0';
	return (line);
}
