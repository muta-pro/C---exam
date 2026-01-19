/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:31:10 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/16 12:20:19 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	int		fds[2];
	pid_t	pid;

	/*validate*/
	if (!file || !argv || !argv[0] || (type != 'r' && type != 'w'))
		return (-1);
	/*pipe*/
	if (pipe(fds) == -1)
		return (-1);
	/*fork*/
	pid = fork();
	if (pid == -1)
		return (close(fds[0]), close(fds[1]), -1);
	/*if child*/
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fds[0]);
			if (dup2(fds[1], STDOUT_FILENO) == -1)
				exit(1);
			close(fds[1]);
		}
		if (type == 'w')
		{
			close(fds[1]);
			if (dup2(fds[0], STDIN_FILENO) == -1)
				exit (1);
			close(fds[0]);
		}
		/*execute*/
		execvp(file, argv);
		exit(1);
	}
	/*if parent*/
	if (type == 'r')
		return (close(fds[1]), fds[0]);
	return (close(fds[0]), fds[1]);
}
