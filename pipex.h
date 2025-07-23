/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:41 by jugarcia          #+#    #+#             */
/*   Updated: 2025/07/09 18:26:41 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

# include "libft/libft.h"

void	ft_free_split(char **arr);

char	*get_cmd_path(char *cmd, char **envp);

void	execute_cmd(char *cmd_str, char **envp);

void	child_one(int *fd, char **argv, char **envp);
void	child_two(int *fd, char **argv, char **envp);

pid_t	create_child_one(int *fd, char **argv, char **envp);
pid_t	create_child_two(int *fd, char **argv, char **envp);
int		setup_and_fork(int *fd, char **argv, char **envp);

void	wait_and_check(pid_t pid, char *cmd);
void	handle_wait(int status, char *cmd);

#endif



