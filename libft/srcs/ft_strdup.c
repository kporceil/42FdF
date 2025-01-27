/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:37:11 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/06 15:43:56 by kporceil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s);
	dup = ft_calloc(size + 1, sizeof(char));
	if (!dup)
		return (NULL);
	dup[size] = s[size];
	while (size--)
		dup[size] = s[size];
	return (dup);
}
