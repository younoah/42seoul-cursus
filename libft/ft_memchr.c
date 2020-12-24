/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:54:59 by ychung            #+#    #+#             */
/*   Updated: 2020/12/22 13:03:15 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(void *ptr, int value, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	find;
	unsigned int	i;

	tmp_ptr = (unsigned char*)ptr;
	find = (unsigned char)value;
	i = 0;
	while (i < n)
	{
		if (tmp_ptr[i] == find)
			return (&tmp_ptr[i]);
		i++;
	}
	return (0);
}

int main() {
	char* pch;
	char str[] = "Example string";
	pch = (char*)ft_memchr(str, 'p', strlen(str));

	if (pch != NULL)
	{
		printf("'p' found at position %ld.\n", pch - str + 1);
		printf("pch : %p  str : %p\n", pch, str);
	}
	else
		printf("'p' not found.\n");

	return 0;
}