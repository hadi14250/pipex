/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:28:53 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/30 02:07:16 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*split_and_join(char *av_cmd, char *splitted)
{
	char	*str;
	char	*path;

	str = ft_strjoin("/", av_cmd);
	path = ft_strjoin(splitted, str);
	free(str);
	return (path);
}

char	*get_path(char *cmd, char *env)
{
	int		i;
	char	*str;
	char	**splitted;

	splitted = ft_split(env, ':');
	i = -1;
	while (++i < word_count(env, ':'))
	{
		str = split_and_join(cmd, splitted[i]);
		if (access(str, X_OK) == 0)
			break ;
		free(splitted[i]);
		splitted[i] = NULL;
		free(str);
		str = NULL;
	}
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		splitted[i++] = NULL;
	}
	free(splitted);
		splitted = NULL;
	return (str);
}

char	*get_appropriate_path(char **env)
{
	char	str[5];
	int		i;

	i = 0;
	str[0] = 'P';
	str[1] = 'A';
	str[2] = 'T';
	str[3] = 'H';
	str[4] = '\0';
	while (env[i] != NULL)
	{
		if (ft_strncmp(str, env[i], 4) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

void	get_exec_args(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->cmd_and_args[i] != NULL)
		i++;
	pipex->execve_args = calloc(i + 1, sizeof(char *));
	i = 0;
	i = 1;
	pipex->execve_args[0] = pipex->path;
	while (pipex->cmd_and_args[i] != NULL)
	{
		pipex->execve_args[i] = pipex->cmd_and_args[i];
		i++;
	}
	pipex->execve_args[i] = NULL;
}

/*
void	check_errors(t_pipex *pipex)
{
	if (errno == 2)
	{
		ft_printf("\033[31mError: \033[0m%s: %s\n", strerror(errno),
			pipex->infile);
		free_double(pipex->cmd1_and_args);
		free_double(pipex->cmd2_and_args);
		close_all(pipex);
		exit (1);
	}
	else if (errno)
	{
		ft_printf("\033[31mError %d: \033[0m%s\n", errno, strerror(errno));
		free_double(pipex->cmd1_and_args);
		free_double(pipex->cmd2_and_args);
		close_all(pipex);
		exit(1);
	}
}

void	close_all(t_pipex *pipex)
{
	if (pipex->dup_infile > -1)
	{
		ft_printf("fd %d got close\n", pipex->dup_infile);
		close(pipex->dup_infile);
	}
	if (pipex->dup_outfile > -1)
	{
		ft_printf("fd %d got close\n", pipex->dup_outfile);
		close(pipex->dup_outfile);
	}
	if (pipex->fd_infile > -1)
	{
		ft_printf("fd %d got close\n", pipex->fd_infile);
		close(pipex->fd_infile);
	}
	if (pipex->fd_oufile > -1)
	{
		ft_printf("fd %d got close\n", pipex->fd_oufile);
		close(pipex->fd_oufile);
	}
	if (pipex->pipe[0] > -1)
	{
		ft_printf("fd %d got close\n", pipex->pipe[0]);
		close(pipex->pipe[0]);
	}
	if (pipex->pipe[1] > -1)
	{
		ft_printf("fd %d got close\n", pipex->pipe[1]);
		close(pipex->pipe[1]);
	}
}
*/