/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:55:07 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/15 02:21:08 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sc_func(t_stack *a)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] - a->arr[i - 1] < 4)
			counter++;
		i++;
	}
	if ((counter * 100 / a->size) >= 60)
		return (0);
	return (-1);
}

void	ca_helper(t_stack *a, t_stack *b, int *cpy, int ch)
{
	int	i;
	int	sc;
	int	size;

	i = 0;
	sc = sc_func(a);
	size = a->size;
	bubble_sort(cpy, a->arr, a->size);
	while (a->size != 0)
	{
		if (a_pos(a->arr[0], cpy, size) <= i)
			(move("pb", a, b), i++);
		else if (a_pos(a->arr[0], cpy, size) <= i + ch)
			(move("pb", a, b), move("rb", NULL, b), i++);
		else
		{
			if (sc == -1)
				move("ra", a, b);
			else
				move("rra", a, NULL);
		}
	}
}

void	clear_a(t_stack *a, t_stack *b)
{
	int	*cpy;
	int	ch;

	cpy = (int *)malloc(a->size * sizeof(int));
	if (!cpy)
		return ;
	if (a->size <= 100)
		ch = 16;
	else
		ch = 36;
	ca_helper(a, b, cpy, ch);
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
