/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:06:50 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 13:35:26 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	is_dup(int *arr, int end)
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
				(print_error(), exit(6));
			j++;
		}
		i++;
	}
}

int	*check_nums(char **args, int size)
{
	int	i;
	int	*arr;

	if (!args || size <= 0)
		return (0);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < size && args[i])
	{
		arr[i] = ft_atoi(args[i]);
		i++;
	}
	return (arr);
}

void	parser(int ac, char **av, t_stack *stack_a)
{
	int		i;
	char	arr[10000];
	char	**args;
	int		*iarr;

	if (ac <= 1)
		exit(0);
	i = 1;
	while (av[i])
	{
		ft_strlcat(arr, av[i], sizeof(arr));
		i++;
		if (av[i])
			ft_strlcat(arr, " ", sizeof(arr));
	}
	args = ft_split(arr, ' ');
	iarr = check_nums(args, i);
	is_dup(iarr, i - 1);
	free_f(args);
	stack_a->arr = iarr;
	stack_a->size = i - 1;
}
