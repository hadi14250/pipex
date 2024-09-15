/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:09:31 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/30 10:56:25 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_space(char *cmd, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0' && cmd[i] == ' ')
		i++;
	if (ft_strlen(cmd) == i)
	{
		ft_printf("\033[31mError:\033[0m invalid command\n");
		close_all(pipex);
		exit(127);
	}
}

void	check_space2(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0' && cmd[i] == ' ')
		i++;
	if (ft_strlen(cmd) == i)
	{
		ft_printf("\033[31mError:\033[0m invalid command\n");
		exit(127);
	}
}

int	initialize(char *cmd, char *infile, t_pipex *pipex, char *outfile)
{
	pipex->infile = infile;
	pipex->outfile = outfile;
	pipex->cmd_and_args = ft_split(cmd, ' ');
	pipex->path = get_path(pipex->cmd_and_args[0],
			get_appropriate_path(pipex->envp));
	get_exec_args(pipex);
	if (!pipex->path)
		return (-1);
	return (0);
}

void	invalid_num_args(int ac, char **av, char *cmd1, char *cmd2)
{
	if (ac < 5 || ac > 5)
	{
		ft_printf("\033[31mError: \033[0minvalid number of arguments\n");
		exit(1);
	}
	if (!av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
	{
		ft_printf("\033[31mError: \033[0minvalid argument\n");
		exit(1);
	}
	check_space2(cmd1);
	check_space2(cmd2);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		d;
	char	*tmp;
	int		size;

	i = 0;
	d = 0;
	size = ft_strlen((char *)s1);
	tmp = (char *)calloc(size + 1, 1);
	if (!tmp)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[d] = s1[i];
		i++;
		d++;
	}
	tmp[d] = '\0';
	return (tmp);
}
