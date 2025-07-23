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

#include "pipex.h"

static void	handle_exit_code(int exit_code, char *cmd)
{
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

static void	handle_signal(int signal_code, char *cmd)
{
	write(2, "Command '", 9);
	write(2, cmd, ft_strlen(cmd));
	write(2, "' terminated by signal ", 23);
	ft_putnbr_fd(128 + signal_code, 2);
	write(2, "\n", 1);
	exit(128 + signal_code);
}

void	handle_wait(int status, char *cmd)
{
	int	exit_code;
	int	signal_code;

	if ((status & 0x7F) == 0)
	{
		exit_code = (status >> 8) & 0xFF;
		handle_exit_code(exit_code, cmd);
	}
	else if ((status & 0x7F) != 0)
	{
		signal_code = status & 0x7F;
		handle_signal(signal_code, cmd);
	}
	exit(1);
}


void	wait_and_check(pid_t pid, char *cmd)
{
	int	status;

	waitpid(pid, &status, 0);
	handle_wait(status, cmd);
}



