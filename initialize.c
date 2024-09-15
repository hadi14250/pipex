/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:09:38 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/30 10:38:56 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_ve(t_pipex *pipex)
{
	if (execve (pipex->execve_args[0], pipex->execve_args, NULL) == -1)
	{
		ft_printf("\033[31mError:\033[0m] %s", strerror(errno));
		ft_free(pipex);
	}
}

void	open_file(t_pipex *pipex, char *file, int flag)
{
	if (flag == 0)
		pipex->fd_file = open(file, O_RDONLY);
	else
		pipex->fd_file = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->fd_file == -1)
	{
		ft_printf("\033[31mError:\033[0m %s: %s\n",
			strerror(errno), file);
		close_all(pipex);
		exit(1);
	}
	if (pipe(pipex->pipe) == -1)
	{
		ft_printf("\033[31mError:\033[0m %s", strerror(errno));
		close_all(pipex);
		exit (1);
	}
}

void	init_fds(t_pipex *pipex)
{
	pipex->fd_file = -1;
	pipex->pipe[0] = -1;
	pipex->pipe[1] = -1;
	pipex->dup_file = -1;
	pipex->wait_param = 0;
	pipex->wait_pid = 0;
	pipex->fork_id = -1;
	pipex->exec_id = -1;
}

void	ft_free_helper(t_pipex *pipex)
{
	if (pipex->execve_args[0])
	{
		free(pipex->execve_args[0]);
		pipex->execve_args[0] = NULL;
	}
	if (pipex->execve_args)
	{
		free(pipex->execve_args);
		pipex->execve_args = NULL;
	}
}

void	exit_after_initialize(t_pipex *pipex_1, t_pipex *pipex_2, int flag)
{
	if (flag == 0)
	{
		ft_printf("\033[31mError: \033[0m: command not found: %s\n",
			pipex_1->cmd_and_args[0]);
		close_all(pipex_1);
		close_all(pipex_2);
		ft_free(pipex_1);
	}
	else
	{
		ft_printf("\033[31mError: \033[0m: command not found: %s\n",
			pipex_2->cmd_and_args[0]);
		close_all(pipex_1);
		ft_free(pipex_1);
		close_all(pipex_2);
		ft_free(pipex_2);
	}
	exit(127);
}
