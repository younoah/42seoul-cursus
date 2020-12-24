/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:41:04 by ychung            #+#    #+#             */
/*   Updated: 2020/12/22 22:52:27 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (count);
}
