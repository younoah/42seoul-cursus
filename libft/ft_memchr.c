/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:54:59 by ychung            #+#    #+#             */
/*   Updated: 2021/01/04 18:29:04 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
