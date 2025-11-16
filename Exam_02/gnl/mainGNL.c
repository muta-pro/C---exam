/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainGNL.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:42:17 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/12 14:16:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	printf ("Reading form test\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Line: [%s]", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\nFinished reading.\n");
	close(fd);
	return (0);
}
