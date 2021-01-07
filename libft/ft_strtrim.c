/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychung <ychung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:48:03 by ychung            #+#    #+#             */
/*   Updated: 2021/01/06 20:43:29 by ychung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return ((char*)s1);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_char_in_set(s1[end], set))
		end--;
	new_s = (char*)malloc(sizeof(char) * (end - start + 2));
	if (!new_s)
		return (0);
	i = 0;
	while (start <= end)
	{
		new_s[i] = s1[start];
		i++;
		start++;
	}
	new_s[i] = 0;
	return (new_s);
}
