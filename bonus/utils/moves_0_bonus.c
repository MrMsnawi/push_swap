/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_0_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:40:53 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/10 15:54:56 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (!move)
		return ;
	if (ft_strcmp(move, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(move, "ss\n") == 0)
		(swap(stack_a), swap(stack_b));
	else if (ft_strcmp(move, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(move, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(move, "rr\n") == 0)
		(rotate(stack_a), rotate(stack_b));
	else if (ft_strcmp(move, "rra\n") == 0)
		rev_r(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		rev_r(stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		(rev_r(stack_a), rev_r(stack_b));
}

void	swap(t_stack *stack_x)
{
	int	tmp;

	if (stack_x->size <= 1)
		return ;
	tmp = stack_x->arr[0];
	stack_x->arr[0] = stack_x->arr[1];
	stack_x->arr[1] = tmp;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	*arr;
	int	*arr2;

	if (stack_b->size == 0)
		return ;
	arr = malloc((stack_a->size + 1) * sizeof(int));
	arr2 = malloc((stack_b->size - 1) * sizeof(int));
	if (!arr || !arr2)
		return ;
	arr[0] = stack_b->arr[0];
	i = -1;
	while (++i < stack_a->size)
		arr[i + 1] = stack_a->arr[i];
	i = -1;
	while (++i < stack_b->size - 1)
		arr2[i] = stack_b->arr[i + 1];
	free(stack_a->arr);
	stack_a->arr = arr;
	stack_a->size += 1;
	free(stack_b->arr);
	stack_b->arr = arr2;
	stack_b->size -= 1;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	*arr;
	int	*arr2;

	if (stack_a->size == 0)
		return ;
	arr = malloc((stack_b->size + 1) * sizeof(int));
	arr2 = malloc((stack_a->size - 1) * sizeof(int));
	if (!arr || !arr2)
		return ;
	arr[0] = stack_a->arr[0];
	i = -1;
	while (++i < stack_b->size)
		arr[i + 1] = stack_b->arr[i];
	i = -1;
	while (++i < stack_a->size - 1)
		arr2[i] = stack_a->arr[i + 1];
	free(stack_b->arr);
	stack_b->arr = arr;
	stack_b->size += 1;
	free(stack_a->arr);
	stack_a->arr = arr2;
	stack_a->size -= 1;
}
