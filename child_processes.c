/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:41 by jugarcia          #+#    #+#             */
/*   Updated: 2025/07/25 21:00:00 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	create_child_one(int *fd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_one(fd, argv, envp);
	return (pid);
}

static pid_t	create_child_two(int *fd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_two(fd, argv, envp);
	return (pid);
}

int	setup_and_fork(int *fd, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		code1;
	int		code2;

	pid1 = create_child_one(fd, argv, envp);
	pid2 = create_child_two(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	code2 = wait_and_check(pid2, argv[3]);
	code1 = wait_and_check(pid1, argv[2]);
	if (code2 != 0)
		return (code2);
	return (code1);
}
