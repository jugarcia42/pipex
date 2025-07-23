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
#include <stdlib.h>
#include <fcntl.h>

static int	validate_args(int argc)
{
	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (!validate_args(argc))
		return (1);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (setup_and_fork(fd, argv, envp));
}
