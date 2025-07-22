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
#include <stdio.h>

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
	{
		write(2, "Command not found\n", 18);
		ft_free_split(args);
		exit(127);
	}
	if (ft_strcmp(cmd_path, "NO_EXEC_PERMISSION") == 0)
	{
		write(2, "Permission denied\n", 18);
		ft_free_split(args);
		free(cmd_path);
		exit(126);
	}
	execve(cmd_path, args, envp);
	perror("execve");
	ft_free_split(args);
	free(cmd_path);
	exit(126);
}

