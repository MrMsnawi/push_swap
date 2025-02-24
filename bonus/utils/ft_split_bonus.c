/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:06:04 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/24 10:04:03 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static size_t	words(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char	**deleting(char **s, int i)
{
	while (--i >= 0 && s[i])
		free(s[i]);
	free(s);
	return (NULL);
}

static int	allocation(char ***buf, size_t words)
{
	*buf = (char **)malloc((words + 1) * sizeof(char *));
	if (*buf == NULL)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*from;
	char	**buf;

	if (s == NULL)
		return (NULL);
	if (allocation(&buf, words(s, c)) == 0)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			buf[i++] = ft_substr(from, 0, ((char *)s - from));
			if (buf[i - 1] == NULL)
				return (deleting(buf, i - 1));
		}
		else
			++s;
	}
	buf[i] = NULL;
	return (buf);
}
