/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:33:28 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 19:33:59 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

char	*join(char *str, char *buf)
{
	int		i;
	size_t	allsize;
	char	*joined;
	int		j;

	if (!str && !buf)
		return (NULL);
	if (!str)
		return (ft_strdup(buf));
	if (!buf)
		return (ft_strdup(str));
	allsize = ft_strlen(str) + ft_strlen(buf);
	joined = malloc(allsize + 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
		joined[i++] = str[j++];
	j = 0;
	while (buf[j])
		joined[i++] = buf[j++];
	joined[i] = '\0';
	return (free(str), str = NULL, joined);
}

char	*s_join(char **str, char *buf)
{
	char	*result;

	result = join(*str, buf);
	*str = result;
	return (result);
}

char	*cleanup(char **str, char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
