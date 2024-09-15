/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 06:03:11 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/30 10:58:04 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!len1 && !len2)
		return (0);
	str = calloc(len1 + len2 + 1, 2);
	if (!str)
		return (0);
	str[0] = '\0';
	while (i < len1 + len2)
	{
		if (i < len1)
			str[i] = s1[i];
		if (i >= len1)
			str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	end_free_close(t_pipex *pipex_0, t_pipex *pipex_1)
{
	close_all(pipex_0);
	close_all(pipex_1);
	ft_free(pipex_0);
	ft_free(pipex_1);
}

void	my_children(int flag, t_pipex *pipex_0, t_pipex *pipex_1)
{
	errno = 0;
	if (flag == 0)
	{
		close(pipex_0->pipe[0]);
		check_errors(pipex_0, pipex_1);
		dup2(pipex_0->fd_file, 0);
		check_errors(pipex_0, pipex_1);
		dup2(pipex_0->pipe[1], 1);
		check_errors(pipex_0, pipex_1);
		execute_ve(pipex_0);
	}
	else
	{
		close(pipex_0->pipe[1]);
		check_errors(pipex_0, pipex_1);
		dup2(pipex_0->pipe[0], 0);
		check_errors(pipex_0, pipex_1);
		dup2(pipex_1->fd_file, 1);
		check_errors(pipex_0, pipex_1);
		execute_ve(pipex_1);
	}
}

void	ft_fork(t_pipex *pipex_0, t_pipex *pipex_1)
{
	pipex_0->fork_id = fork();
	if (pipex_0->fork_id == 0)
	{
		pipex_1->fork_id = fork();
		if (pipex_1->fork_id == 0)
			my_children(pipex_1->fork_id, pipex_0, pipex_1);
		else
			my_children(pipex_1->fork_id, pipex_0, pipex_1);
	}
	else
		end_free_close(pipex_0, pipex_1);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex[2];

	invalid_num_args(ac, av, av[2], av[3]);
	init_env_file(&pipex[0], env, P_0, av[1]);
	init_env_file(&pipex[1], env, P_1, av[4]);
	if (initialize(av[2], av[1], &pipex[0], av[4]) == -1)
		exit_after_initialize(&pipex[0], &pipex[1], P_0);
	if (initialize(av[3], av[1], &pipex[1], av[4]) == -1)
		exit_after_initialize(&pipex[0], &pipex[1], P_1);
	ft_fork(&pipex[0], &pipex[1]);
	return (0);
}

/*
make re && rm *.o && clear && valgrind ./pipex hadi_txt ls pwd outfile
*/

/*
 make re && rm *.o && clear && valgrind  --track-fds=yes --leak-check=full
   ./pipex hadi_txt "pwd -c" "vim -e" outfile
*/