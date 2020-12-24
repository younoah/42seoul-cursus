/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:00:14 by ychung            #+#    #+#             */
/*   Updated: 2020/12/22 23:15:16 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h> // 삭제하기

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;

	dest_len = strlen(dest); //ft_strlen()으로 바꾸기
	src_len = strlen(src); //ft_strlen()으로 바꾸기
	if (size <= dest_len)
		return (src_len + size);
	else
	{
		i = 0;
		while ((i < size - 1) && src[i])
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = 0;
		return (src_len + dest_len);
	}
}

#include <stdio.h>
int		main()
{
	char src[] = "saysomthing";
	char dst[10] = "goods";
	printf("return (5+11) : %zu, dst(goodssay) : %s\n", ft_strlcat(dst, src, 9), dst);
}