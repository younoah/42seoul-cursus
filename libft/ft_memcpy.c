/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:55:06 by ychung            #+#    #+#             */
/*   Updated: 2020/12/21 20:58:10 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
}

int main() {
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];

	ft_memcpy(str2, str1, strlen(str1) + 1);
	ft_memcpy(str3, "copy successful", 16);
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}