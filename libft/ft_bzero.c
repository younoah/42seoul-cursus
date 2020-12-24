/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:21:58 by ychung            #+#    #+#             */
/*   Updated: 2020/12/21 20:34:39 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*temp;
	int				i;

	temp = ptr;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

int		main()
{
	char str1[] = "almost every programmer should know memset!";
	char str2[] = "almost every programmer should know memset!";

	bzero(str1, 1);
	printf("bzero : %s\n", str1);
	ft_bzero(str2, 1);
	printf("bzero : %s\n", str2);
	return (0);
}