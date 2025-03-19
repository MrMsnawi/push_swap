/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:59:56 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 18:18:34 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	print_error(void)
{
	ft_putstr_fd(RED_COLOR"Error\n"END_COLOR, 2);
}

void	free_f(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

int	is_sorted(t_stack *stack_x)
{
	int	i;

	i = 0;
	while (i < stack_x->size - 1)
	{
		if (stack_x->arr[i] > stack_x->arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}
