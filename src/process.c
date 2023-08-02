/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:09:43 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/11 14:37:47 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pid_zero(t_pipe pipex, int *fd_pipe, int i)
{
	pipex.tab_of_all_path = path_without_command(pipex.envp);
	if (pipex.tab_of_all_path == NULL)
		message_perror("Impossible to find PATH=");
	path(&pipex, i, pipex.argv);
	if (i == pipex.nb_commands -1)
	{
		if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(pipex.outfile);
	if (pipex.path != NULL)
		execute_command(pipex);
}

void	pid_not_zero(int *fd_pipe)
{
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
}

void	after_fork(pid_t pid, t_pipe pipex, int *fd_pipe, int i)
{
	int	status;

	status = 0; 
	if (pid == 0)
		pid_zero(pipex, fd_pipe, i);
	else if (pid != 0)
		pid_not_zero(fd_pipe);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == 1)
		status_code_failure(pipex);
}

void	to_fork(t_pipe pipex)
{
	int		i;
	pid_t	pid;
	int		fd_pipe[2];

	i = 0;
	pid = 1;
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pipex.infile);
	while (i < pipex.nb_commands)
	{
		if (pipe(fd_pipe) == -1)
			exit(message_perror("Problem "));
		if (pid != 0)
		{
			pid = fork();
			if (pid == -1)
				exit(message_perror("Error"));
			after_fork(pid, pipex, fd_pipe, i);
		}
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		i++;
	}
}
