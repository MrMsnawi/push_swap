/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:36:41 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/11 14:00:18 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	max_n(t_stack *a)
{
	int	i;
	int	max;

	if (!a || a->size == 0)
		return (0);
	i = -1;
	max = a->arr[0];
	while (++i < a->size)
	{
		if (max < a->arr[i])
			max = a->arr[i];
	}
	return (max);
}

int	min_n(t_stack *a)
{
	int	i;
	int	min;

	if (!a || a->size == 0)
		return (0);
	i = -1;
	min = a->arr[0];
	while (++i < a->size)
	{
		if (min > a->arr[i])
			min = a->arr[i];
	}
	return (min);
}

int	a_pos(int a_el, int *cpy, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (cpy[i] == a_el)
			return (i);
	}
	return (-1);
}
