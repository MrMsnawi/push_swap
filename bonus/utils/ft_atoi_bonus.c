/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:04:15 by abmasnao          #+#    #+#             */
/*   Updated: 2025/03/02 09:11:07 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	ft_atoi(char *str, char **args, int *arr)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	--i;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - 48);
		else
			(free(arr), free_f(args), print_error(), exit(4));
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		(free(arr), free_f(args), print_error(), exit(5));
	return (res * sign);
}
