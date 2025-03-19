/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:51:15 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/15 02:51:41 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	empty_check(int ac, char **av)
{
	int	i;
	int	j;
	int	is_space_exist;

	i = 0;
	is_space_exist = 0;
	while (++i < ac)
	{
		j = -1;
		if (!av[i][0])
			(print_error(), exit(1));
		while (av[i][++j])
		{
			if (av[i][j] != ' ')
				is_space_exist = 1;
			if (av[i][j] == '\t')
				(print_error(), exit(1));
		}
		if (is_space_exist == 0)
			(print_error(), exit(1));
	}
}

void	plus_minus_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0)
			{
				if ((av[i][j] == '+' || av[i][j] == '-')
					&& (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
					(print_error(), exit(1));
			}
			else
			{
				if (((av[i][j] == '+' || av[i][j] == '-')
				&& !(av[i][j - 1] == ' ' && (av[i][j + 1] >= '0'
				&& av[i][j + 1] <= '9'))) || (ft_strlen(av[i]) == 1
				&& (av[i][0] < '0' || av[i][j] > '9')))
					(print_error(), exit(1));
			}
		}
	}
}

void	invalid_char(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			while (av[i][j] == ' ' || av[i][j] == '+' || av[i][j] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				(print_error(), exit(1));
		}
	}
}

int	*stoi(char **args)
{
	int	i;
	int	*arr;
	int	index;

	i = 0;
	index = -1;
	while (args[i])
		i++;
	arr = (int *)malloc(i * sizeof(int));
	if (!arr)
	{
		free_f(args);
		return (0);
	}
	while (++index < i)
		arr[index] = ft_atoi(args[index], args, arr);
	return (arr);
}

void	dup_check(int *arr, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < end - 1)
	{
		j = i + 1;
		while (j < end)
		{
			if (arr[i] == arr[j])
				(free(arr), print_error(), exit(1));
			j++;
		}
		i++;
	}
}
