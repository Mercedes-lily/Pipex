/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:13:09 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/30 12:54:37 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
}	t_pipe;

//file_and_exec_bonus.c
int		ft_dup_child_b(t_pipe *pipex, int *fd_pipe, int i);
int		ft_dup_parent_b(t_pipe *pipex, int *fd_pipe, int i);
int		in_and_out_b(int argc, char **argv, t_pipe *pipex);
int		execute_command_b(t_pipe pipex);

//free_message_bonus.c
int		message_sans_perror_b(void);
int		message_perror_b(char *str);
void	free_tab_b(char **tab);
void	status_code_failure_b(int *fd_pipe, t_pipe pipex);

//path_bonus.c
char	*find_all_path_b(char **envp);
char	**path_without_command_b(char **envp);
int		join_path_command_b(char **tab_of_path, char *command);
char	*test_path_b(char **tab_of_path);
void	path_b(t_pipe *pipex, int i, char **argv);

//process.c
void	pid_zero_b(t_pipe pipex, int *fd_pipe, char **argv, int i);
void	pid_not_zero_b(int *fd_pipe);
void	to_fork_b(t_pipe pipex, char **argv);
#endif