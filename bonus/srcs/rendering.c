/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:03:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/02/09 15:33:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "map.h"
#include <stddef.h>

void	apply_translation(t_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			map_data->rendered_point[i][j].x += map_data->x_center;
			map_data->rendered_point[i][j++].y += map_data->y_center;
		}
		++i;
	}
}

void	apply_projection(t_data *map)
{
	size_t		i;
	size_t		j;
	int			x;
	int			z;
	int			y;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			x = map->map[i][j].x;
			z = map->map[i][j].z;
			y = map->map[i][j].y;
			rotate_x(&x, &y, &z, map);
			rotate_y(&x, &z, map);
			rotate_z(&x, &y, map);
			map->rendered_point[i][j].x = x;
			map->rendered_point[i][j].y = y;
			map->rendered_point[i][j].color.rgba = map->map[i][j].color.rgba;
			++j;
		}
		++i;
	}
}

void	render_map(t_data *map_data)
{
	apply_projection(map_data);
	apply_translation(map_data);
}
