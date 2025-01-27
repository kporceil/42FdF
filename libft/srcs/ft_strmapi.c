/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:20:34 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/07 14:21:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dup;
	unsigned int	i;

	i = 0;
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
