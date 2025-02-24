/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:15:39 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/22 13:34:02 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_b.arr = NULL;
	stack_b.size = 0;
	parser(ac, av, &stack_a);
	sort(&stack_a, &stack_b);
	free(stack_a.arr);
}
