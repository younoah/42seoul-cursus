/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:59:19 by ychung            #+#    #+#             */
/*   Updated: 2020/12/22 12:46:45 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	unsigned int	i;

	tmp_dest = (unsigned char*)dest;
	tmp_src = (unsigned char*)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tmp_dest[n - 1 - i] = tmp_src[n - 1 - i];
			i++;
		}
	}
	return (dest);
}

int main() {
	char str[] = "memmove can be very useful......";
	ft_memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}
