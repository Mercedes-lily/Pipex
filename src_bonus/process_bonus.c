/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:09:43 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/30 12:58:38 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	pid_zero_b(t_pipe pipex, int *fd_pipe, char **argv, int i)
{
	path_b(&pipex, i, argv);
	if (i == pipex.nb_commands -1)
	{
		if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		close(pipex.outfile);
	}
	else
	{
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		close(pipex.outfile);
	}
	execute_command_b(pipex);
}

void	pid_not_zero_b(int *fd_pipe)
{
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
}

void	to_fork_b(t_pipe pipex, char **argv)
{
	int		i;
	pid_t	pid;
	int		status;
	int		fd_pipe[2];

	i = 0;
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pipex.infile);
	while (i < pipex.nb_commands)
	{
		if (pipe(fd_pipe) == -1)
			exit(message_perror_b("Problem "));
		pid = fork();
		if (pid == -1)
			exit(message_perror_b("Error"));
		else if (pid == 0)
			pid_zero_b(pipex, fd_pipe, argv, i);
		if (pid != 0)
			pid_not_zero_b(fd_pipe);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) == 1)
			status_code_failure_b(fd_pipe, pipex);
		i++;
	}
}
