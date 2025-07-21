/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:54 by jugarcia          #+#    #+#             */
/*   Updated: 2025/07/09 18:26:54 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

static void	child_one(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("infile");
		exit(1);
	}
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute_cmd(argv[2], envp);
}

static void	child_two(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("outfile");
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	execute_cmd(argv[3], envp);
}

static int	wait_and_return(pid_t pid1, pid_t pid2, int *fd)
{
	int	status;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return ((status >> 8) & 0xFF);
}

static int	setup_and_fork(int *fd, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == 0)
		child_one(fd, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		child_two(fd, argv, envp);
	return (wait_and_return(pid1, pid2, fd));
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 41);
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (setup_and_fork(fd, argv, envp));
}
