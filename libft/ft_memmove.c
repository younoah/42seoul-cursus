/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:59:19 by ychung            #+#    #+#             */
/*   Updated: 2021/01/07 22:51:06 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *usrc;
	unsigned char *udst;
	unsigned char temp[len];

	if (!dst && !src)
		return (0);
	usrc = (unsigned char *)src;
	udst = (unsigned char *)dst;
	ft_memcpy(temp, usrc, len);
	ft_memcpy(udst, temp, len);
	return (dst);
}
