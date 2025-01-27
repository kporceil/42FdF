/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:31 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 11:25:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "parsing.h"

size_t	count_col(char *line)
{
	size_t	i;
	size_t	col;

	i = 0;
	col = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			++i;
		if (line[i])
			++col;
		while (line[i] && !ft_isspace(line[i]))
			++i;
	}
	return (col);
}

int	check_file_extension(char *name, char *extension)
{
	size_t	extension_i;
	size_t	name_i;

	extension_i = ft_strlen(extension);
	name_i = ft_strlen(name);
	if (extension_i >= name_i)
		return (-1);
	while (--extension_i)
	{
		--name_i;
		if (extension[extension_i] != name[name_i])
			return (-1);
	}
	return (0);
}
