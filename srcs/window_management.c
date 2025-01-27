/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:26:05 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 20:04:51 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "map.h"
#include "mlx.h"
#include "render.h"
#include "hook.h"


static void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = image->data + (y * image->size_line + x * (image->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	render_points_to_image(t_mlx *mlx)
{
	t_point	*p;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mlx->map_data->line)
	{
		j = 0;
		while (j < mlx->map_data->line)
		{
			p = mlx->map_data->rendered_point[i] + j;
			put_pixel_to_image(&mlx->image, p->x, p->y, p->color.rgba);
			++j;
		}
		++i;
	}
}

static void	set_min_and_max(t_data *map_data, int *min, int *max)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->line)
	{
		j = 0;
		while (j < map_data->col)
		{
			if (map_data->rendered_point[i][j].x < min[0])
				min[0] = map_data->rendered_point[i][j].x;
			else if (map_data->rendered_point[i][j].x > max[0])
				max[0] = map_data->rendered_point[i][j].x;
			if (map_data->rendered_point[i][j].y < min[1])
				min[1] = map_data->rendered_point[i][j].y;
			else if (map_data->rendered_point[i][j].y > max[1])
				max[1] = map_data->rendered_point[i][j].y;
			++j;
		}
		++i;
	}
}

static void	auto_zoom(t_data *map_data)
{
	int	min[2];
	int	max[2];

	ft_memset(min, 0, sizeof(int) * 2);
	ft_memset(max, 0, sizeof(int) * 2);
	set_min_and_max(map_data, min, max);
	if (WINDOW_WIDTH / (max[0] - min[0]) < WINDOW_HEIGHT / (max[1] - min[1]))
		apply_zoom(map_data, (WINDOW_WIDTH / (max[0] - min[0])) * 0.9);
	else
		apply_zoom(map_data, (WINDOW_HEIGHT / (max[1] - min[1])) * 0.9);
}

static void	auto_translation(t_data *map_data)
{
	int	min[2];
	int	max[2];
	int	center_x;
	int	center_y;

	ft_memset(min, 0, sizeof(int) * 2);
	ft_memset(max, 0, sizeof(int) * 2);
	set_min_and_max(map_data, min, max);
	center_x = (WINDOW_WIDTH >> 1) - ((min[0] + max[0]) >> 1);
	center_y = (WINDOW_HEIGHT >> 1) - ((min[1] + max[1]) >> 1);
	apply_translation(map_data, center_x, center_y, 0);
}

int	create_window_and_render(t_data *map_data)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (-1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	if (!mlx.win_ptr)
		return (-1);
	//NEW IMAGE :
	mlx.image.img_ptr = mlx_new_image(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.image.data = mlx_get_data_addr(mlx.image.img_ptr, &mlx.image.bpp,
			&mlx.image.size_line, &mlx.image.endian);
	mlx.map_data = map_data;
	auto_zoom(map_data);
	auto_translation(map_data);
	render_points_to_image(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.image.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, handle_keypress, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
