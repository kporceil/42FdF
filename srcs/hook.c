/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:18:36 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 20:10:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "map.h"
#include "render.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 114)
		apply_zoom(mlx->map_data, 1.1);
	else if(keycode == 102)
		apply_zoom(mlx->map_data, 0.9);
	else if (keycode == 65362)
		apply_translation(mlx->map_data, 0, -1, 0);
	else if (keycode == 65364)
		apply_translation(mlx->map_data, 0, 1, 0);
	else if (keycode == 65363)
		apply_translation(mlx->map_data, 1, 0, 0);
	else if (keycode == 65361)
		apply_translation(mlx->map_data, -1, 0, 0);
	else
		return (0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->image.img_ptr);
	mlx->image.img_ptr = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->image.data = mlx_get_data_addr(mlx->image.img_ptr, &mlx->image.bpp,
			&mlx->image.size_line, &mlx->image.endian);
	render_points_to_image(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img_ptr, 0, 0);
	return (0);
}
