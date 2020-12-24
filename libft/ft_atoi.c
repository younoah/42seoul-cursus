/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:17:15 by ychung            #+#    #+#             */
/*   Updated: 2020/12/24 18:54:02 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign *= (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[] = "--2147483647";
	int num = ft_atoi(s);
	printf("res : %d\n", num);
	return (0);
}