/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:35:27 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/08 00:35:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;
	size_t	i;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < len_s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2 && s2[i])
	{
		join[len_s1 + i] = s2[i];
		i++;
	}
	join[len_s1 + len_s2] = 0;
	return (join);
}
