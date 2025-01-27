/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:14:15 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/05 00:18:34 by kporceil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;
	size_t				i;

	i = -1;
	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	while (++i < n)
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
	return (0);
}
