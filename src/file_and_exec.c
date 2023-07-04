/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:55:04 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/30 13:00:50 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_dup_child(t_pipe *pipex, int *fd_pipe, int i)
{	
	if (i == pipex->nb_commands - 1)
		pipex->output = pipex->outfile;
	else
		pipex->output = fd_pipe[1];
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		return (message_perror("Impossible to change STDOUT"));
	return (0);
}

int	ft_dup_parent(t_pipe *pipex, int *fd_pipe, int i)
{	
	if (i == 0)
	pipex->input = pipex->infile;
	else
		pipex->input = fd_pipe[0];
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		return (message_perror("Impossible to change STDIN"));
	return (0);
}

//open infile and outfile
int	in_and_out(int argc, char **argv, t_pipe *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		return (message_perror("Problem to open the infile"));
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		return (message_perror("Problem to open the outfile"));
	return (0);
}

int	execute_command(t_pipe pipex)
{
	free(pipex.command[0]);
	pipex.command[0] = ft_calloc(ft_strlen(pipex.path) + 1, sizeof(char));
	if (pipex.command[0] == NULL)
		exit(EXIT_FAILURE);
	ft_strlcpy(pipex.command[0], pipex.path, ft_strlen(pipex.path) + 1);
	if (execve(pipex.path, pipex.command, NULL) == -1)
		return (message_perror("Probleme to execute the command "));
	return (0);
}
