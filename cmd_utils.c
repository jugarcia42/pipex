/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:27:03 by jugarcia          #+#    #+#             */
/*   Updated: 2025/07/09 18:27:03 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path_cmd(char *path, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

static char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full;
	int		i;
	int		found_no_exec;

	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	found_no_exec = 0;
	i = 0;
	while (paths[i])
	{
		full = join_path_cmd(paths[i], cmd);
		if (!full)
			break ;
		if (access(full, F_OK) == 0)
		{
			if (access(full, X_OK) == 0)
			{
				ft_free_split(paths);
				return (full);
			}
			else
				found_no_exec = 1;
		}
		free(full);
		i++;
	}
	ft_free_split(paths);
	if (found_no_exec)
		return (ft_strdup("NO_EXEC_PERMISSION"));
	return (NULL);
}
