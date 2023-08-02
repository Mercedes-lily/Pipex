/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:13:09 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/11 14:29:54 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//open function
# include <fcntl.h>
//close, read, write, access, dup, dup2, execve, fork, pipe, unlink functions
# include <unistd.h>
//malloc, free, exit functions			
# include <stdlib.h>
//perror function
# include <stdio.h>
//strerror function
# include <string.h>
// wait and the waitpid functions
# include <sys/wait.h>
// libft functions
# include "../libft/libft.h"

typedef struct pipe_list
{
	char	**tab_of_all_path ;
	char	*path;
	int		nb_commands;
	int		nb_pipe;
	int		input;
	int		output;
	int		infile;
	int		outfile;
	char	**command;
	char	**tab_execve;
	char	**envp;
	char	**argv;
}	t_pipe;

//file_and_exec.c
int		ft_dup_child(t_pipe *pipex, int *fd_pipe, int i);
int		ft_dup_parent(t_pipe *pipex, int *fd_pipe, int i);
int		in_and_out(int argc, char **argv, t_pipe *pipex);
int		execute_command(t_pipe pipex);

//free_message.c
int		message_sans_perror(void);
int		message_perror(char *str);
void	free_tab(char **tab);
void	status_code_failure(t_pipe pipex);

//path.c
char	*find_all_path(char **envp);
char	**path_without_command(char **envp);
int		join_path_command(char **tab_of_path, char *command);
char	*test_path(char **tab_of_path);
void	path(t_pipe *pipex, int i, char **argv);

//process.c
void	pid_zero(t_pipe pipex, int *fd_pipe, int i);
void	pid_not_zero(int *fd_pipe);
void	to_fork(t_pipe pipex);
#endif