/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:21:47 by ychung            #+#    #+#             */
/*   Updated: 2020/12/23 22:40:37 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	return (0);
}

#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "This is a sample string";
	char* pch;
	printf("Looking for the 's' character in \"%s\"...\n", str);

	pch = ft_strchr(str, 's');

	while (pch != NULL) {
		printf("found at %ld\n", pch - str + 1);
		pch = ft_strchr(pch + 1, 's');
	}

	return 0;
}