/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:40:55 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/30 13:22:23 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	if (argc != 5)
		return (message_sans_perror());
	if (in_and_out(argc, argv, &pipex) == 1)
		return (EXIT_FAILURE);
	pipex.nb_commands = argc -3;
	pipex.nb_pipe = pipex.nb_commands -1;
	pipex.tab_of_all_path = path_without_command(envp);
	if (pipex.tab_of_all_path == NULL)
		return (message_perror("Impossible to find PATH="));
	to_fork(pipex, argv);
	free_tab(pipex.tab_of_all_path);
	close(pipex.outfile);
}
