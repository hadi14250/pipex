/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:43:46 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/30 10:46:14 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/errno.h>
# include <string.h>
# include <stdarg.h>
# include <sys/wait.h>

/*extern char **environ;*/

typedef struct t_pipe
{
	char	*infile;
	char	*outfile;
	int		fd_file;
	int		pipe[2];
	char	**envp;
	int		dup_file;
	int		exec_id;
	int		fork_id;
	int		wait_param;
	pid_t	wait_pid;
	char	**cmd_and_args;
	char	*path;
	char	**execve_args;
}			t_pipex;

# define P_0 0
# define P_1 1
/*			******	printf.c	******				*/

int		ft_putchar(char c);

int		ft_putnbr(int nb);

int		ft_putstr(char *str);

int		ft_put_hex(unsigned int nb, char c);

int		ft_putnbr_u(unsigned int nb);

int		ft_put_address(unsigned long long nb);

int		ft_parse(va_list ptr, char c);

int		ft_printf(const char *str, ...);

/*			******	pipex.c	******				*/

// void	close_all(t_pipex *pipex);

void	print_all(t_pipex pipex);

// void	check_errors(t_pipex *pipex);

// void	parse(int ac, char **av, char **env, t_pipex *pipex);

void	invalid_num_args(int ac, char **av, char *cmd1, char *cmd2);

void	dup_it(t_pipex *pipex);

int		initialize(char *cmd, char *infile, t_pipex *pipex, char *outfile);

int		ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(const char *s1);

int		word_count(char const *s, char c);

char	**ft_split(char const *s, char c);

char	*split_and_join(char *av_cmd, char *splitted);

char	**join_args(char *path, char **cmds);

void	look_for_cmd(char **av, char **env);

char	*ft_substr(char const *s, int start, int len);

char	*split_and_join(char *av_cmd, char *splitted);

// void	print_error_exit(char *av, t_pipex *pipex);

char	*get_path(char *cmd, char *env);

int		ft_strncmp(char *s1, char *s2, size_t n);

char	*get_appropriate_path(char **env);

// void	ft_free_path(t_pipex *pipex);

void	get_exec_args(t_pipex *pipex);

// void	simple_exit(t_pipex *pipex);

void	ft_free_helper(t_pipex *pipex);

void	ft_free(t_pipex *pipex);

void	init_env(t_pipex *pipex, char **env);

void	init_fds(t_pipex *pipex);

void	init_env_file(t_pipex *pipex, char **env, int flag, char *file);

void	execute_ve(t_pipex *pipex);

void	open_file(t_pipex *pipex, char *file, int flag);

void	close_all(t_pipex *pipex);

void	check_space(char *cmd, t_pipex *pipex);

void	exit_after_initialize(t_pipex *pipex_1, t_pipex *pipex_2, int flag);

void	check_errors(t_pipex *pipex_0, t_pipex *pipex_1);

void	my_children(int flag, t_pipex *pipex_0, t_pipex *pipex_1);

#endif
