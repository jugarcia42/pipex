#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	execute_cmd(char *cmd_str, char **envp)
{
	char	*cmd[] = {"pipex", "-c", cmd_str, NULL};

	execve("/bin/sh", cmd, envp);
	perror("execve");
	exit(1);
}
