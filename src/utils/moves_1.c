/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:15:07 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 13:51:55 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *stack_x)
{
	int	i;
	int	*arr;

	if (stack_x->size <= 1)
		return ;
	arr = malloc(stack_x->size * sizeof(int));
	if (!arr)
		return ;
	i = -1;
	while (++i < stack_x->size - 1)
		arr[i] = stack_x->arr[i + 1];
	arr[i] = stack_x->arr[0];
	free(stack_x->arr);
	stack_x->arr = arr;
}

void	rev_r(t_stack *stack_x)
{
	int	i;
	int	*arr;

	if (stack_x->size <= 1)
		return ;
	arr = malloc(stack_x->size * sizeof(int));
	if (!arr)
		return ;
	arr[0] = stack_x->arr[stack_x->size - 1];
	i = 0;
	while (++i < stack_x->size)
		arr[i] = stack_x->arr[i - 1];
	free(stack_x->arr);
	stack_x->arr = arr;
}
