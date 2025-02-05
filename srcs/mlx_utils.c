/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/02/05 20:16:42 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"
#include "render.h"
#include "libft.h"
#include "hook.h"
#include <X11/X.h>
#include <stdlib.h>

static void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = image->data + (y * image->size_line + x * (image->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

static void	draw_line(t_image *image, t_point p1, t_point p2)
{
	const int	d[2] = {abs(p2.x - p1.x), abs(p2.y - p1.y)};
	const int	s[2] = {((p1.x < p2.x) + (p1.x < p2.x) - 1),
		((p1.y < p2.y) + (p1.y < p2.y) - 1)};
	int			err[2];

	err[0] = -d[1] / 2;
	if (d[0] > d[1])
		err[0] = d[0] / 2;
	while (1)
	{
		put_pixel_to_image(image, p1.x, p1.y, p1.color.rgba);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		err[1] = err[0];
		if (err[1] > -d[0])
		{
			err[0] -= d[1];
			p1.x += s[0];
		}
		if (err[1] < d[1])
		{
			err[0] += d[0];
			p1.y += s[1];
		}
	}
}

void	render_points_to_image(t_mlx *mlx)
{
	t_point	*p1;
	t_point	*p2;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mlx->map_data->line)
	{
		j = 0;
		while (j < mlx->map_data->col)
		{
			p1 = mlx->map_data->rendered_point[i] + j;
			p2 = mlx->map_data->rendered_point[i] + (j + 1);
			if (j + 1 < mlx->map_data->col)
				draw_line(&mlx->image, *p1, *p2);
			p2 = mlx->map_data->rendered_point[i + 1] + j;
			if (i + 1 < mlx->map_data->line)
				draw_line(&mlx->image, *p1, *p2);
			++j;
		}
		++i;
	}
}

void	display_map(t_mlx *mlx)
{
	ft_bzero(mlx->image.data, WINDOW_HEIGHT * WINDOW_WIDTH
		* (mlx->image.bpp / 8));
	render_points_to_image(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img_ptr,
		0, 0);
}

int	init_mlx(t_mlx *mlx, t_data *map_data)
{
	mlx->map_data = map_data;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (-1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"kporceil's FdF");
	if (!mlx->win_ptr)
		return (-1);
	mlx->image.img_ptr = mlx_new_image(mlx->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->image.img_ptr)
		return (-1);
	mlx->image.data = mlx_get_data_addr(mlx->image.img_ptr, &mlx->image.bpp,
			&mlx->image.size_line, &mlx->image.endian);
	if (!mlx->image.data)
		return (-1);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, handle_key, mlx);
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, handle_destroy, mlx);
	return (0);
}
