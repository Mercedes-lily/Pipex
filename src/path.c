/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:47:08 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/10 13:17:00 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_all_path(char **envp)
{
	int	index_tab;

	index_tab = 0;
	while (envp[index_tab] != NULL)
	{
		if (ft_strncmp("PATH=", envp[index_tab], 5) == 0)
			return (envp[index_tab] + 5);
		index_tab++;
	}
	return (NULL);
}

char	**path_without_command(char **envp)
{
	char	*all_path;

	all_path = find_all_path(envp);
	if (all_path == NULL)
	{
		message_perror("Impossible to find PATH= ");
		return (NULL);
	}
	return (ft_split(all_path, ':'));
}

int	join_path_command(char **tab_of_path, char *command)
{
	int	index_path;

	index_path = 0;
	while (tab_of_path[index_path])
	{
		tab_of_path[index_path] = ft_strjoin(tab_of_path[index_path], "/");
		index_path++;
	}
	index_path = 0;
	while (tab_of_path[index_path])
	{
		tab_of_path[index_path] = ft_strjoin(tab_of_path[index_path], command);
		index_path++;
	}
	return (0);
}

char	*test_path(char **tab_of_path)
{
	int		index_tab_of_path;
	char	*good_path;
	int		path_len;

	index_tab_of_path = 0;
	while (tab_of_path[index_tab_of_path])
	{
		if (access(tab_of_path[index_tab_of_path], X_OK) == 0)
		{
			path_len = ft_strlen(tab_of_path[index_tab_of_path]) + 1;
			good_path = ft_calloc(path_len, sizeof(char));
			if (!good_path)
				return (NULL);
			ft_strlcpy(good_path, tab_of_path[index_tab_of_path], path_len);
			free_tab(tab_of_path);
			return (good_path);
		}
		index_tab_of_path++;
	}
	free_tab(tab_of_path);
	return (NULL);
}

void	path(t_pipe *pipex, int i, char **argv)
{
	pipex->command = ft_split(argv[i + 2], ' ');
	join_path_command(pipex->tab_of_all_path, pipex->command[0]);
	pipex->path = test_path(pipex->tab_of_all_path);
	if (pipex->path == NULL)
	{
		free_tab(pipex->command);
		perror("Wrong command");
	}
}
