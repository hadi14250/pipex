/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 04:20:25 by hakaddou          #+#    #+#             */
/*   Updated: 2022/05/29 04:21:00 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;
	int	done;

	i = 0;
	cnt = 0;
	done = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && !done)
			done = 1;
		else if (s[i] != c && done)
		{
			++cnt;
			done = 0;
		}
		++i;
	}
	return (cnt);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*tmp;
	int		i;

	if (!s || len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (ft_strlen(s) < len)
		tmp = (char *)calloc(ft_strlen(&s[start]), 2);
	else
		tmp = (char *)calloc(len + 1, 2);
	if (!tmp)
		return (0);
	while (start < ft_strlen(s) && i < len)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			words;
	char		**tmp;

	if (!s)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	tmp = calloc(sizeof(char *), (words + 2));
	if (!tmp)
		return (NULL);
	words = 0;
	while (s[i] && words < word_count(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tmp[words++] = ft_substr(s + i, 0, j);
		i += j;
	}
	tmp[words] = 0;
	return (tmp);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2 || n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
