/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 14:58:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "map.h"
#include "get_next_line.h"
#include "memory.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>

static int	set_map_line_col(char *file, t_data *map_data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, READ);
	if (!line)
		return (-1);
	map_data->col = count_col(line);
	while (line && ++(map_data->line))
	{
		if (count_col(line) != map_data->col)
		{
			free(line);
			close(fd);
			get_next_line(fd, DELETE);
			return (-1);
		}
		free(line);
		line = get_next_line(fd, READ);
	}
	close(fd);
	return (0);
}

static int	map_alloc_col(t_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map_data->line)
	{
		map_data->map[i] = ft_calloc(sizeof(t_point), map_data->col);
		if (map_data->map[i] == NULL)
		{
			while (j < i)
				free(map_data->map[j++]);
			return (-1);
		}
		++i;
	}
	return (0);
}

static int	fill_line(t_point *map_line, char *line, size_t line_nb)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = line;
	while (*ptr1 && *ptr1 != '\n')
	{
		map_line[i].x = i;
		map_line[i].y = line_nb;
		map_line[i].z = ft_strtol(ptr1, &ptr2, 10);
		if (ptr1 == ptr2)
			return (-1);
		ptr1 = ptr2;
		if (*ptr2 == ',')
			map_line[i].color.rgba = ft_strtol(ptr2 + 1, &ptr1, 16);
		else
			map_line[i].color.rgba = 0xFFFFFF;
		while (ft_isspace(*ptr1))
			++ptr1;
		++i;
	}
	return (0);
}

static int	set_point_data(char *file, t_data *map_data)
{
	int		fd;
	char	*line;
	size_t	y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, READ);
	if (!line)
		return (-1);
	y = 0;
	while (line)
	{
		if (fill_line(map_data->map[y], line, y) == -1)
		{
			free(line);
			get_next_line(fd, DELETE);
			return (close(fd), -1);
		}
		++y;
		free(line);
		line = get_next_line(fd, READ);
	}
	close (fd);
	return (0);
}

int	parse_map(char *file, t_data *map_data)
{
	if (set_map_line_col(file, map_data) != 0)
		return (-1);
	map_data->map = malloc(sizeof(t_point *) * (map_data->line));
	map_data->rendered_point = NULL;
	if (!(map_data->map))
		return (-1);
	if (map_alloc_col(map_data) != 0)
	{
		free(map_data->map);
		return (-1);
	}
	if (set_point_data(file, map_data) != 0)
	{
		free_points(map_data);
		return (-1);
	}
	return (0);
}
