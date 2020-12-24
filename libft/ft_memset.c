/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:38:51 by ychung            #+#    #+#             */
/*   Updated: 2020/12/21 20:32:39 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*temp;
	int				i;
	
	temp = ptr;
	i = 0;
	while (i < n)
	{
		temp[i] = value;
		i++;
	}
	return (ptr);
}

int main() {
	char str[] = "almost every programmer should know memset!";
	long long *numPtr = malloc(sizeof(long long));

	memset(str, '-', 6);
	printf("memset : %s\n", str);
	ft_memset(str, '-', 6);
	printf("ft_memset : %s\n", str);
	
	memset(numPtr, 0x27, 8);
	printf("memset : %llx\n", *numPtr);
	ft_memset(numPtr, 0x27, 8);
	printf("ft_memset : %llx\n", *numPtr);

	free(numPtr);
	return 0;
}