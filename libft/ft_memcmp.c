/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:18:51 by ychung            #+#    #+#             */
/*   Updated: 2020/12/22 13:24:22 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*tmp_ptr1;
	unsigned char	*tmp_ptr2;
	unsigned int	i;

	tmp_ptr1 = (unsigned char*)ptr1;
	tmp_ptr2 = (unsigned char*)ptr2;
	i = 0;
	while (i < n)
	{
		if (tmp_ptr1[i] != tmp_ptr2[i])
			return (tmp_ptr1[i] - tmp_ptr2[i]);
		i++;
	}
	return (0);
}

int main ()
{
	char str1[12];
	char str2[12];
	int state;

	strcpy(str1, "mozi");
	strcpy(str2, "tistory");

	state = ft_memcmp( &str1, &str2, 4 );

	printf ("State=\"%d\", str1=\"%s\", str2=\"%s\"\n", state, str1, str2);
	return 0;
}