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
#include <stdlib.h>

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

static void	wait_and_check(pid_t pid, char *cmd)
{
	int	status;
	int	exit_code;
	int	signal_code;

	waitpid(pid, &status, 0);
	if ((status & 0x7F) == 0) // proceso terminó normalmente
	{
		exit_code = (status >> 8) & 0xFF;
		if (exit_code == 127)
		{
			write(2, "Command not found: ", 20);
			write(2, cmd, ft_strlen(cmd));
			write(2, "\n", 1);
		}
		else if (exit_code == 126)
		{
			write(2, "Permission denied: ", 20);
			write(2, cmd, ft_strlen(cmd));
			write(2, "\n", 1);
		}
		exit(exit_code);
	}
	else if ((status & 0x7F) != 0) // terminó por señal
	{
		signal_code = status & 0x7F;
		write(2, "Command '", 9);
		write(2, cmd, ft_strlen(cmd));
		write(2, "' terminated by signal ", 24);
		ft_putnbr_fd(128 + signal_code, 2); // si tienes esta función en libft
		write(2, "\n", 1);
		exit(128 + signal_code);
	}
	exit(1);
}


static int	setup_and_fork(int *fd, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid1 == 0)
		child_one(fd, argv, envp);

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid2 == 0)
		child_two(fd, argv, envp);

	close(fd[0]);
	close(fd[1]);

	wait_and_check(pid1, argv[2]);
	wait_and_check(pid2, argv[3]);
	return (0); // nunca llegará aquí si wait_and_check llama a exit
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

