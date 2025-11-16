/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:58:55 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/14 11:23:27 by imutavdz         ###   ########.fr       */
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
	size_t	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, const char *src, size_t n)
{
	size_t	i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	str_apped_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);

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

int str_apped_str(char **s1, char *s2)
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
		while (i > n)
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
	char		*ret = NULL;
	char		*tmp = ft_strchr(b, '\n');
	int			read_ret;

	while (!tmp)
	{
		if (!str_apped_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(ret);
			return (NULL);
		}
		b[read_ret] = '\0';
		if (read_ret == 0)
		{
			if (ret && *ret)
				return (ret);
			free(ret);
			return (NULL);
		}
		tmp = ft_strchr(b, '\n');
	}
	if (!str_apped_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1));
	b[ft_strlen(tmp + 1)] = '\0';
	return (ret);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
