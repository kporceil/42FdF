/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:02:47 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/10 22:50:45 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free_all(char **tab, size_t i_tab)
{
	size_t	i;

	i = 0;
	while (i < i_tab)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_fill_tab(char **tab, char const *s, char c, size_t words)
{
	size_t	start;
	size_t	end;
	size_t	i_tab;

	start = 0;
	i_tab = 0;
	while (i_tab < words)
	{
		end = 0;
		while (s[start] && s[start] == c)
			start++;
		while (s[start + end] && s[start + end] != c)
			end++;
		tab[i_tab] = ft_substr(s, start, end);
		if (!tab[i_tab])
			return (ft_free_all(tab, i_tab));
		start += end;
		i_tab++;
	}
	tab[i_tab] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	words = ft_countwords(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = ft_fill_tab(tab, s, c, words);
	return (tab);
}
