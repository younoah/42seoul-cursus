/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:01:48 by ychung            #+#    #+#             */
/*   Updated: 2020/12/24 18:03:59 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "This is a simple string";
	char* pch;
	pch = ft_strnstr(str, "simple", 5); // 15이하로 설정하면 null출력
	printf("pch : %s\n", pch);
	return 0;
}