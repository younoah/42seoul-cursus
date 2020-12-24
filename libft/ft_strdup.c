/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:19:59 by ychung            #+#    #+#             */
/*   Updated: 2020/12/24 20:28:48 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*res;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

#include <stdio.h>

int main()
{
	char *line = "hello world!";
	char *dupstr = NULL;

	dupstr = ft_strdup (line);
	printf("%s\n", dupstr);
	free(dupstr);
}