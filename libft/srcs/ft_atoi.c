/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:40:51 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/10 23:52:08 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

static size_t	pass_whitespace_and_set_sign(const char *nptr, int8_t *s)
{
	size_t	i;

	i = 0;
	while (nptr[i] && ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		*s = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr, int *nb)
{
	size_t	i;
	int8_t	sign;

	sign = 1;
	i = pass_whitespace_and_set_sign(nptr, &sign);
	*nb = 0;
	while (nptr[i] && nptr[i] > 47 && nptr[i] < 58)
	{
		if (sign == -1 && (INT_MIN / 10 > -(*nb)
				|| 10 * -(*nb) < INT_MIN + (nptr[i] - 48)))
			return (-1);
		if (sign == 1 && (INT_MAX / 10 < *nb
				|| *nb * 10 > INT_MAX - (nptr[i] - 48)))
			return (-1);
		*nb = *nb * 10 + (nptr[i++] - 48);
	}
	*nb = *nb * sign;
	return (0);
}
