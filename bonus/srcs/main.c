/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:06:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/02/05 17:47:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "map.h"
#include "memory.h"
#include "render.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float	set_scale(t_data *map_data)
{
	float	projected_width;
	float	projected_height;
	int		max_z;
	size_t	i;
	size_t	j;

	max_z = 0;
	i = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			if (map_data->map[i][j].z > max_z)
				max_z = map_data->map[i][j].z;
			++j;
		}
		++i;
	}
	projected_width = (map_data->col + map_data->line) * cos(M_PI / 6);
	projected_height = (map_data->col + map_data->line) * cos(M_PI / 6) + max_z;
	if (WINDOW_WIDTH / projected_width > WINDOW_HEIGHT / projected_height)
		return ((WINDOW_HEIGHT / projected_height) * 0.8);
	return ((WINDOW_WIDTH / projected_width) * 0.8);
}

int	init_data(t_data *map_data)
{
	map_data->z_factor = 1;
	map_data->x_center = (WINDOW_WIDTH >> 1) - (map_data->col >> 1);
	map_data->y_center = (WINDOW_HEIGHT >> 1) - (map_data->line >> 1);
	map_data->scale = set_scale(map_data);
	map_data->rendered_point = NULL;
	map_data->r_z = 0.22;
	map_data->r_x = M_PI / 4;
	map_data->r_y = atan(sin(M_PI / 6));
	if (duplicate_map(map_data) != 0)
		return (-1);
	return (0);
}

void	end_and_free_all(t_mlx *mlx)
{
	if (mlx->mlx_ptr && mlx->image.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image.img_ptr);
	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
	free_points(mlx->map_data);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	map_data;

	if (argc != 2)
		return (1);
	if (check_file_extension(argv[1], ".fdf") != 0)
		return (2);
	map_data.col = 0;
	map_data.line = 0;
	if (parse_map(argv[1], &map_data) != 0)
		return (3);
	if (init_data(&map_data) != 0)
		return (end_and_free_all(&mlx), 4);
	render_map(&map_data);
	if (init_mlx(&mlx, &map_data) != 0)
		return (end_and_free_all(&mlx), 5);
	display_map(&mlx);
	mlx_loop(mlx.mlx_ptr);
	end_and_free_all(&mlx);
	return (0);
}
