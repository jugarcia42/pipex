/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:48 by jugarcia          #+#    #+#             */
/*   Updated: 2025/07/09 18:26:48 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_and_exit(char **args, char *cmd_path, int code)
{
	ft_free_split(args);
	if (cmd_path)
		free(cmd_path);
	exit(code);
}

void	execute_cmd(char *cmd_str, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd_str, ' ');
	if (!args || !args[0])
	{
		write(2, "Invalid command\n", 16);
		exit(127);
	}
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
		free_and_exit(args, NULL, 127);
	if (ft_strcmp(cmd_path, "NO_EXEC_PERMISSION") == 0)
		free_and_exit(args, cmd_path, 126);
	execve(cmd_path, args, envp);
	perror("execve");
	free_and_exit(args, cmd_path, 126);
}
