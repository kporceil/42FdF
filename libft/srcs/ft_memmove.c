/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:03:39 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/05 01:36:44 by kporceil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	if (dest > src)
		while (n-- && (dest || src))
			cdest[n] = csrc[n];
	else
	{
		while (i < n && (dest || src))
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
