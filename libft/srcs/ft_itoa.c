/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:00:00 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/08 03:00:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_get_len(long nb)
{
	size_t	len;
	long	ten_power;

	ten_power = 10;
	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb >= ten_power)
	{
		ten_power *= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nb;

	nb = (long) n;
	len = ft_get_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb / 10)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	str[len--] = nb % 10 + '0';
	return (str);
}
