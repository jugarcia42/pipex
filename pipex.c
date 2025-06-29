#include "pipex.h"
#include <stdio.h>

void	execute_cmd(char *cmd_str, char **envp)
{
	char	**args;
	char	*cmd;

	args = ft_split(cmd_str, ' ');
	if (!args || !args[0])
	{
		write(2, "Invalid command\n", 16);
		exit(1);
	}
	cmd = get_cmd_path(args[0], envp);
	if (!cmd)
	{
		write(2, "Command not found\n", 18);
		exit(1);
	}
	execve(cmd, args, envp);
	perror("execve");
	exit(1);
}
