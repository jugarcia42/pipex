#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>

static void	child_one(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror("infile");
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	execute_cmd(argv[2], envp);
}

static void	child_two(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		perror("outfile");
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 41);
		return (1);
	}
	if (pipe(fd) == -1)
		perror("pipe");
	pid1 = fork();
	if (pid1 == 0)
		child_one(fd, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		child_two(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
