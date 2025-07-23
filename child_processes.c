/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:41 by jugarcia          #+#    #+#             */
/*   Updated: 2025/07/09 18:26:41 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t create_child_one(int *fd, char **argv, char **envp)
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_one(fd, argv, envp);
	return pid;
}

static pid_t create_child_two(int *fd, char **argv, char **envp)
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_two(fd, argv, envp);
	return pid;
}

int setup_and_fork(int *fd, char **argv, char **envp)
{
	pid_t pid1 = create_child_one(fd, argv, envp);
	pid_t pid2 = create_child_two(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	wait_and_check(pid1, argv[2]);
	wait_and_check(pid2, argv[3]);
	return 0;
}
