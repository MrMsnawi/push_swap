/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:55:07 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 16:42:48 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	clear_a(t_stack *a, t_stack *b)
{
	int	i;
	int	ch;
	int	*cpy;
	int	size;

	size = a->size;
	cpy = (int *)malloc(a->size * sizeof(int));
	if (!cpy)
		return ;
	if (a->size <= 100)
		ch = 16;
	else
		ch = 36;
	i = 0;
	bubble_sort(cpy, a->arr, a->size);
	while (a->size != 0)
	{
		if (a_pos(a->arr[0], cpy, size) <= i)
			(move("pb", a, b), i++);
		else if (a_pos(a->arr[0], cpy, size) <= i + ch)
			(move("pb", a, b), move("rb", NULL, b), i++);
		else
			move("ra", a, b);
	}
	free(cpy);
}

void	clear_b(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (b->size > 1)
	{
		pos = get_max(b, &max);
		if (pos <= b->size / 2)
		{
			while (b->arr[0] != max)
				move("rb", NULL, b);
			move("pa", a, b);
		}
		else if (pos > b->size / 2)
		{
			while (b->arr[0] != max)
				move("rrb", NULL, b);
			move("pa", a, b);
		}
	}
	move("pa", a, b);
}

void	sorting(t_stack *a, t_stack*b)
{
	if (!a)
		return ;
	clear_a(a, b);
	clear_b(a, b);
}
