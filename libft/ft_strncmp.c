/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:04:20 by ychung            #+#    #+#             */
/*   Updated: 2020/12/24 18:46:04 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int main() {
	char str[][5] = {"R2D2", "C3PO", "R2A6"};
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
		if (ft_strncmp(str[n], "R2xx", 2) == 0) {
		printf("found %s\n", str[n]);
		}
	return 0;
}