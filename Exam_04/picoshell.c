/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:20:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/16 12:44:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int		fds[2];
	int		prev_fds;
	pid_t	pid;
	int		has_next;
	int		i;

	prev_fds = -1;
	i = 0;
	while (cmds[i])
	{
		has_next = (cmds[i + 1] != 0);
		if (has_next && pipe(fds) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			if (has_next)
			{
				close(fds[0]);
				close(fds[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (prev_fds != -1)
			{
				if (dup2(prev_fds, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fds);
			}
			if (has_next)
			{
				close(fds[0]);
				if (dup2(fds[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fds[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit (1);
		}
		if (prev_fds != 1)
			close(prev_fds);
		if (has_next)
		{
			close(fds[1]);
			prev_fds = fds[0];
		}
		i++;
	}
	while (wait(0) > 0)
		;
	return (0);
}
