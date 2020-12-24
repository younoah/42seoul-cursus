/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:06:41 by ychung            #+#    #+#             */
/*   Updated: 2020/12/21 21:37:05 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	unsigned int	i;

	tmp_dest = dest;
	tmp_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == c)
			return (&dest[i + 1]);
		i++;
	}
	return (0);
}

int main() {
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];

	int *res1 = ft_memccpy(str2, str1, 's', strlen(str1) + 1);
	int *res2 =  ft_memccpy(str3, "copy successful", 'u', 14) ;
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	printf("res1 : %p\nres2 : %p", res1, res2);
	return 0;
}