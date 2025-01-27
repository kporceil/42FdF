/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:58:05 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/13 05:14:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	while (i < n && (dest || src))
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
