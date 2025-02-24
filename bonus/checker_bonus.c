/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:48:22 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/24 14:09:16 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker_bonus.h"
#include <stdio.h>

void	is_valid_action(char *arr)
{
	if (!arr)
		return ;
	if (ft_strcmp(arr, "sa\n") != 0
		&& ft_strcmp(arr, "sb\n") != 0
		&& ft_strcmp(arr, "ss\n") != 0
		&& ft_strcmp(arr, "pa\n") != 0
		&& ft_strcmp(arr, "pb\n") != 0
		&& ft_strcmp(arr, "ra\n") != 0
		&& ft_strcmp(arr, "rb\n") != 0
		&& ft_strcmp(arr, "rr\n") != 0
		&& ft_strcmp(arr, "rra\n") != 0
		&& ft_strcmp(arr, "rrb\n") != 0
		&& ft_strcmp(arr, "rrr\n") != 0)
	{
		print_error();
		exit(10);
	}
}

void	get_moves(t_stack *a, t_stack *b)
{
	char	*arr;
	int		flag;

	if (!a)
		return ;
	arr = NULL;
	flag = 1;
	while (flag || arr)
	{
		flag = 0;
		arr = get_next_line(0);
		is_valid_action(arr);
		move(arr, a, b);
		free(arr);
	}
	if (is_sorted(a) == 0 && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	b.arr = NULL;
	b.size = 0;
	parser(ac, av, &a);
	get_moves(&a, &b);
	free(a.arr);
}
