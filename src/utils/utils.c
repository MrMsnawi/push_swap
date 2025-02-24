/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:04:29 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 13:45:06 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

int	get_max(t_stack *b, int *max)
{
	int	i;
	int	position;

	i = -1;
	position = 0;
	*max = b->arr[0];
	while (++i < b->size)
	{
		if (b->arr[i] > *max)
		{
			*max = b->arr[i];
			position = i;
		}
	}
	return (position);
}

void	bubble_sort(int *cpy, int *original, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
		cpy[i] = original[i];
	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (cpy[i] > cpy[j])
			{
				tmp = cpy[i];
				cpy[i] = cpy[j];
				cpy[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
