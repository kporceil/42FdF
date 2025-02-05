/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:17 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 15:12:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "memory.h"
#include <stdlib.h>
#include <sys/types.h>

void	free_points(t_data *map_data)
{
	size_t	i;

	i = 0;
	while (i < map_data->line)
	{
		free(map_data->map[i]);
		if (map_data->rendered_point)
			free(map_data->rendered_point[i]);
		++i;
	}
	if (map_data->rendered_point)
		free(map_data->rendered_point);
	free(map_data->map);
}

int	duplicate_map(t_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	map_data->rendered_point = malloc(sizeof(t_point *) * map_data->line);
	if (!map_data->rendered_point)
		return (-1);
	while (i < map_data->line)
	{
		map_data->rendered_point[i] = malloc(sizeof(t_point) * map_data->col);
		if (!map_data->rendered_point[i])
		{
			j = 0;
			while (j < i)
				free(map_data->rendered_point[j++]);
			return (-1);
		}
		++i;
	}
	return (0);
}
