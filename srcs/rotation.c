/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:32:33 by kporceil          #+#    #+#             */
/*   Updated: 2025/02/09 15:32:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "render.h"
#include <math.h>

void	rotate_x(int *x, int *y, int *z, t_data *map)
{
	int	temp_z;
	int	temp_y;

	*x = *x - ((map->col - 1) >> 1);
	*y = *y - ((map->line - 1) >> 1);
	*y *= map->scale;
	*x *= map->scale;
	*z *= map->z_factor * map->scale;
	temp_y = cos(map->r_x) * *y - sin(map->r_x) * *z;
	temp_z = sin(map->r_x) * *y + cos(map->r_x) * *z;
	*z = temp_z;
	*y = temp_y;
}

void	rotate_y(int *x, int *z, t_data *map)
{
	const int	temp_z = -sin(map->r_y) * *x + cos(map->r_y) * *z;
	const int	temp_x = cos(map->r_y) * *x + sin(map->r_y) * *z;

	*x = temp_x;
	*z = temp_z;
}

void	rotate_z(int *x, int *y, t_data *map)
{
	const int	temp_x = cos(map->r_z) * *x - sin(map->r_z) * *y;
	const int	temp_y = sin(map->r_z) * *x + cos(map->r_z) * *y;

	*x = temp_x + ((map->col - 1) >> 1);
	*y = temp_y + ((map->line - 1) >> 1);
}
