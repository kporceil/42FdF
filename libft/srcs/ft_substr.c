/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:47:59 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/11 05:27:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	malloc_size;
	size_t	s_len;
	char	*sub_s;

	s_len = ft_strlen(s);
	malloc_size = 0;
	i = 0;
	while (start + malloc_size < s_len && malloc_size < len)
		malloc_size++;
	sub_s = ft_calloc(malloc_size + 1, sizeof(char));
	if (!sub_s)
		return (NULL);
	while (i < malloc_size && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = 0;
	return (sub_s);
}
