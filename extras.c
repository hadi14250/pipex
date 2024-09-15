/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:56:03 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/30 10:58:07 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_all(t_pipex pipex)
{
	int	i;

	i = -1;
	ft_printf("infile is called: %s\n", pipex.infile);
	ft_printf("Fd is: %d\n", pipex.fd_file);
	ft_printf("outfile is called: %s\n", pipex.outfile);
	ft_printf("cmd1 is: %s\n", pipex.cmd_and_args[0]);
	while (pipex.execve_args[++i] != NULL)
		ft_printf("execve_args[%d] is: %s\n", i, pipex.execve_args[i]);
	write(1, "\n", 1);
}

void	ft_free(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmd_and_args[++i] != NULL)
	{
		if (pipex->cmd_and_args[i])
		{
			free(pipex->cmd_and_args[i]);
			pipex->cmd_and_args[i] = NULL;
		}
	}
	if (pipex->cmd_and_args)
	{
		free(pipex->cmd_and_args);
		pipex->cmd_and_args = NULL;
	}
	ft_free_helper(pipex);
}

void	close_all(t_pipex *pipex)
{
	errno = 0;
	if (pipex->fd_file > 0)
	{
		close(pipex->fd_file);
		pipex->fd_file = -1;
	}
	if (pipex->pipe[0] > -1)
	{
		close(pipex->pipe[0]);
		pipex->pipe[0] = -1;
	}
	if (pipex->pipe[1] > -1)
	{
		close(pipex->pipe[1]);
		pipex->pipe[1] = -1;
	}
	if (pipex->dup_file > -1)
	{
		close(pipex->dup_file);
		pipex->dup_file = -1;
	}
	if (errno)
		ft_printf("\033[31mClose Error:\033[0m %s\n");
}

void	check_errors(t_pipex *pipex_0, t_pipex *pipex_1)
{
	if (errno)
	{
		ft_printf("\033[31mError:\033[0m %s\n", strerror(errno));
		ft_free(pipex_0);
		ft_free(pipex_1);
		exit(errno);
	}
}

void	init_env_file(t_pipex *pipex, char **env, int flag, char *file)
{
	pipex->envp = env;
	init_fds(pipex);
	open_file(pipex, file, flag);
}
