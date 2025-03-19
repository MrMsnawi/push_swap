/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:57:01 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/15 02:51:01 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_cat(char **av, char *arr)
{
	int	i;

	i = 1;
	while (av[i])
	{
		ft_strlcat(arr, av[i], sizeof(arr));
		i++;
		if (av[i])
			ft_strlcat(arr, " ", sizeof(arr));
	}
}

void	parser_2(char *arr, t_stack *a)
{
	int		i;
	int		*tab;
	char	**args;

	i = 0;
	tab = NULL;
	args = NULL;
	args = ft_split(arr, ' ');
	if (!args)
		return ;
	tab = stoi(args);
	i = 0;
	while (args[i])
		i++;
	free_f(args);
	dup_check(tab, i);
	a->arr = tab;
	a->size = i;
}

void	parser(int ac, char **av, t_stack *a)
{
	int		i;
	char	arr[10000];

	if (ac == 1)
		exit(0);
	i = 1;
	ft_bzero(arr, sizeof(arr) / sizeof(arr[0]));
	empty_check(ac, av);
	plus_minus_check(ac, av);
	invalid_char(ac, av);
	while (av[i])
	{
		ft_strlcat(arr, av[i], sizeof(arr));
		i++;
		if (av[i])
			ft_strlcat(arr, " ", sizeof(arr));
	}
	parser_2(arr, a);
}
