/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:53:17 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/30 13:00:55 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	message_sans_perror(void)
{
	write(1, "ERROR", 5);
	return (EXIT_FAILURE);
}

int	message_perror(char *str)
{
	perror(str);
	return (EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	index_tab;

	index_tab = 0;
	while (tab[index_tab])
	{
		free(tab[index_tab]);
		index_tab++;
	}
	free(tab);
}

void	status_code_failure(int *fd_pipe, t_pipe pipex)
{
	free_tab(pipex.tab_of_all_path);
	free(fd_pipe);
	exit(EXIT_FAILURE);
}
