/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:43:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 20:06:23 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "memory.h"
#include "render.h"
#include <math.h>

void	isometric_projection(t_data *map_data)
{
	float	angle;
	size_t	i;
	size_t	j;

	angle = M_PI / 6;
	i = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			map_data->rendered_point[i][j].z = 0;
			map_data->rendered_point[i][j].color.rgba
				= map_data->map[i][j].color.rgba;
			map_data->rendered_point[i][j].x = (map_data->map[i][j].x
					- map_data->map[i][j].y) * cos(angle);
			map_data->rendered_point[i][j].y = (map_data->map[i][j].x
					+ map_data->map[i][j].y) * sin(angle)
				- map_data->map[i][j].z;
			++j;
		}
		++i;
	}
}

void	apply_translation(t_data *map_data, int dx, int dy, int dz)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			map_data->rendered_point[i][j].x += dx;
			map_data->rendered_point[i][j].y += dy;
			map_data->rendered_point[i][j].z += dz;
			++j;
		}
		++i;
	}
}

void	apply_zoom(t_data *map_data, float scale)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			map_data->rendered_point[i][j].x *= scale;
			map_data->rendered_point[i][j].y *= scale;
			++j;
		}
		++i;
	}
}

int	rendering_map(t_data *map_data)
{
	if (duplicate_map(map_data) != 0)
		return (-1);
	isometric_projection(map_data);
	create_window_and_render(map_data);
	return (0);
}
