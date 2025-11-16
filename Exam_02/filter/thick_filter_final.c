/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thick_filter_final.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:46:30 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/10 16:38:24 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

#ifndef BUF_SIZE
# define BUF_SIZE 4096
#endif

typedef struct
{
	unsigned char		*buf;
	unsigned char		*stars_b;
	const unsigned char	*patt;
	size_t				carry_len;
	size_t				patt_len;
	int					eof;
	size_t				capacity;
}						t_filter_data;

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

static int	handle_error(const char *msg)
{
	fprintf(stderr, "error %s\n", msg);
	return (1);
}

static int	extend_buffer(t_filter_data *data)
{
	size_t	extra_cap;
	void	*extra_buf;

	extra_cap = data->capacity * 2;
	if (extra_cap == 0)
		extra_cap = BUF_SIZE;
	extra_buf = realloc(data->buf, extra_cap);
	if (extra_buf == NULL)
		return (handle_error("realloc"));
	data->buf = (unsigned char *)extra_buf;
	data->capacity = extra_cap;
	return (0);
}

static int	init_filter(t_filter_data *data, const char *patt_str)
{
	size_t	i;

	data->buf = NULL;
	data->stars_b = NULL;
	data->carry_len = 0;
	data->eof = 0;
	data->patt = (const unsigned char *)patt_str;
	data->patt_len = strlen(patt_str);
	if (data->patt_len == 0)
		return (1);
	data->stars_b = (unsigned char *)malloc(data->patt_len);
	if (data->stars_b == NULL)
		return (handle_error("malloc"));
	i = 0;
	while (i < data->patt_len)
	{
		data->stars_b[i] = '*';
		i++;
	}
	data->capacity = (data->patt_len - 1) + BUF_SIZE;
	if (data->capacity == 0)
		data->capacity = 1;
	data->buf = (unsigned char *)malloc(data->capacity);
	if (data->buf == NULL)
	{
		free(data->stars_b);
		return (handle_error("malloc"));
	}
	return (0);
}

static int	run_filter(t_filter_data *data)
{
	ssize_t	rd;
	size_t	tot_bytes_buf;
	size_t	safe_search;
	size_t	pos_start_idx;
	size_t	i;
	void	*hitp;

	while (!data->eof)
	{
		rd = read(STDIN_FILENO, data->buf + data->carry_len,
				data->capacity - data->carry_len);
		if (rd < 0)
			return (handle_error("read"));
		if (rd == 0)
			data->eof = 1;
		tot_bytes_buf = data->carry_len + (size_t)rd;
		if (data->eof)
			safe_search = tot_bytes_buf;
		else if (tot_bytes_buf > data->patt_len - 1)
			safe_search = tot_bytes_buf - (data->patt_len - 1);
		else
			safe_search = 0;
		i = 0;
		while (i < safe_search)
		{
			hitp = memmem(data->buf + i, tot_bytes_buf - i,
					data->patt, data->patt_len);
			if (hitp == NULL || (size_t)((unsigned char *)hitp - data->buf) >= safe_search)
			{
				if (write_all(STDOUT_FILENO, data->buf + i, safe_search - i) < 0)
					return (handle_error("write"));
				i = safe_search;
			}
			else
			{
				pos_start_idx = (size_t)((unsigned char *)hitp - data->buf);
				if (write_all(STDOUT_FILENO, data->buf + i, pos_start_idx - i) < 0)
					return (handle_error("write"));
				if (write_all(STDOUT_FILENO, data->stars_b, data->patt_len) < 0)
					return (handle_error("write"));
				i = pos_start_idx + data->patt_len;
			}
		}
		data->carry_len = tot_bytes_buf - i;
		if (data->carry_len > 0)
			memmove(data->buf, data->buf + i, data->carry_len); //carry-over
		if (!data->eof && data->carry_len == data->capacity)
		{
			if (extend_buffer(data) != 0)
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_filter_data	data;
	int				result;

	if (argc != 2 || argv[1] == NULL || argv[1][0] == 0)
		return (1);
	if (init_filter(&data, argv[1]) != 0)
		return (1);
	result = run_filter(&data);
	free(data.buf);
	free(data.stars_b);
	return (result);
}
