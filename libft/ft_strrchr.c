/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:49:14 by ychung            #+#    #+#             */
/*   Updated: 2020/12/24 17:32:33 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = strlen(s);
	while(i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

int main() {
	char str[] = "This is a sample string";
	char* pch;
	pch = ft_strrchr(str, 's');
	printf("Last occurence of 's' found at %ld \n", pch - str + 1);
	return 0;
}