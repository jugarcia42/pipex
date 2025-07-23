#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

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

static void	handle_wait(int status, char *cmd)
{
	int	exit_code;
	int	signal_code;

	if ((status & 0x7F) == 0)
	{
		exit_code = (status >> 8) & 0xFF;
		if (exit_code == 127)
		{
			write(2, "Command not found: ", 19);
			write(2, cmd, ft_strlen(cmd));
			write(2, "\n", 1);
		}
		else if (exit_code == 126)
		{
			write(2, "Permission denied: ", 19);
			write(2, cmd, ft_strlen(cmd));
			write(2, "\n", 1);
		}
		exit(exit_code);
	}
	else if ((status & 0x7F) != 0)
	{
		signal_code = status & 0x7F;
		write(2, "Command '", 9);
		write(2, cmd, ft_strlen(cmd));
		write(2, "' terminated by signal ", 23);
		ft_putnbr_fd(128 + signal_code, 2);
		write(2, "\n", 1);
		exit(128 + signal_code);
	}
	exit(1);
}

static void	wait_and_check(pid_t pid, char *cmd)
{
	int	status;

	waitpid(pid, &status, 0);
	handle_wait(status, cmd);
}

int	setup_and_fork(int *fd, char **argv, char **envp)
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
	return (0);
}
