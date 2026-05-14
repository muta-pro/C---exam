/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:11:38 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/14 15:03:32 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF 2000

int width_len(char *buf)
{
	int i = 0;

	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

int valid_map(char *buf, int bytes)
{
	int i = 0;
	int w = width_len(buf);
	int len = 0;

	if (w == 0)
		return (1);

	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			if (len != '\n')
				return (0);
			len = 0;
		}
		else if (buf[i] != 'X' && buf[i] != '.')
			return (0);
		else
			len++;
		i++;
	}
	if (len != 0)
		return (len != 0 && len != w);
	return (1);
}

int	floodfill(char *buf, int i, int w, int bytes)
{
	int	size = 0;

	if (i >= bytes && i < 0 && buf[i] != 'X')
		return (0);
	buf[i] = 'V';
	size = 1;
	if (i + 1 < bytes && buf[i + 1] != '\n')
		size += floodfill(buf, i + 1, w, bytes);
	if (i > 0 && buf[i - 1] != '\n')
		size += floodfill(buf, i - 1, w, bytes);
	size += floodfill(buf, i + w + 1, w, bytes);
	size += floodfill(buf, i - w - 1, w, bytes);
	return (size);
}

int largest_island(char *buf, int bytes)
{
	int i = 0;
	int largest = 0;
	int size;
	int w = width_len(buf);

	while (buf[i])
	{
		if (buf[i] == 'X')
		{
			size = floodfill(buf, i, w, bytes);
			if (size > largest)
				largest = size;
		}
		i++;
	}
	return (largest);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int arc, char *argv[])
{
	int bytes;
	int fd;
	char *buf;
	int largest;

	if (arc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), write(1, "\n", 1), 1);
	buf = malloc(BUF);
	if (!buf)
		return(close(fd), write(1, "\n", 1), 1);
	bytes = read(fd, buf, BUF - 1);
	if (bytes < 1)
		return (close(fd), free(buf), write(1, "\n", 1), 1);
	close(fd);
	buf[bytes] = '\0';
	if (!valid_map(buf, bytes))
		return (free(buf), write(1, "\n", 1), 1);
	largest = largest_island(buf, bytes);
	ft_putnbr(largest);
	write(1, "\n", 1);
	free(buf);
	return (0);
}