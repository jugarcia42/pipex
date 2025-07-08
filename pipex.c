#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void execute_cmd(char *cmd_str, char **envp)
{
    char **args;
    char *cmd_path;

    args = ft_split(cmd_str, ' ');
    if (!args || !args[0])
    {
        write(2, "Invalid command\n", 16);
        exit(1);
    }

    cmd_path = get_cmd_path(args[0], envp);
    if (!cmd_path)
    {
        write(2, "Command not found\n", 18);
        ft_free_split(args);
        exit(127);
    }

    execve(cmd_path, args, envp);

    perror("execve");
    ft_free_split(args);
    free(cmd_path);
    exit(1);
}
