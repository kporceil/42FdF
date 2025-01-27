/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:15 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/11 00:06:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (((const unsigned char *)s)[i] == (const unsigned char)c)
			return ((char *)s + i);
	if (((const unsigned char *)s)[i] == (const unsigned char)c)
		return ((char *)s + i);
	return (0);
}
