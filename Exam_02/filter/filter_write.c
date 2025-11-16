/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:16:46 by imutavdz          #+#    #+#             */
/*   Updated: 2025/10/30 10:56:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#ifndef BUF_SIZE
# define BUF_SIZE 4096
#endif

static int	write_all(int fd, const void *buf, size_t len)
{
	const char	*p;
	ssize_t		w;

	p = (const char *)buf;
	while (len > 0)
	{
		w = write(fd, p, len);
		if (w < 0)
			return (-1);
		p += (size_t)w;
		len -= (size_t)w;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char		buf[BUF_SIZE];
	ssize_t		rd;

	if (argc != 2 || argv[1] == NULL || argv[1][0] == '\0')
		return (1);
	rd = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "read %zd bytes\n", rd);
	while (rd > 0)
	{
		if (write_all(STDOUT_FILENO, buf, (size_t)rd) < 0)
		{
			fprintf(stderr, "error: write\n");
			return (1);
		}
		rd = read(STDIN_FILENO, buf, sizeof(buf));
		fprintf(stderr, "read %zd bytes\n", rd);
	}
	if (rd < 0)
	{
		fprintf(stderr, "Error: read\n");
		return (1);
	}
	return (0);
}
