/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:06:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 15:16:42 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "map.h"
#include "render.h"
#include <stdio.h>

int	print_map(t_data *map_data)
{
	size_t	i;
	size_t	j;
	size_t	nbr_point;

	i = 0;
	nbr_point = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			printf("point number : %zu\n", nbr_point);
			printf("basic coordonate :\n");
			printf("\tx : %d\n\ty : %d\n\tz : %d\n\tcolor : %#x\n\n", map_data->map[i][j].x, map_data->map[i][j].y, map_data->map[i][j].z, map_data->map[i][j].color.rgba);
			printf("rendered coordonate :\n");
			printf("\tx : %d\n\ty : %d\n\tz : %d\n\tcolor : %#x\n\n", map_data->rendered_point[i][j].x, map_data->rendered_point[i][j].y, map_data->rendered_point[i][j].z, map_data->rendered_point[i][j].color.rgba);
			++j;
			++nbr_point;
		}
		++i;
	}
	printf("number of point : %zu\n", map_data->col * map_data->line);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	map_data;

	map_data.col = 0;
	map_data.line = 0;
	if (argc != 2)
		return (1);
	if (check_file_extension(argv[1], ".fdf") != 0)
		return (2);
	if (parse_map(argv[1], &map_data) != 0)
		return (3);
	if (rendering_map(&map_data) != 0)
		return (4);
	if (print_map(&map_data) != 0)
		return (4);
	return (0);
}
