/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:15:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/02/05 20:16:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "map.h"
#include "render.h"
#include "mlx.h"
#include "X11/keysym.h"

int	handle_destroy(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	handle_key2(int keycode, t_mlx *mlx)
{
	if (keycode == XK_r)
		mlx->map_data->scale *= 1.1;
	else if (keycode == XK_f)
		mlx->map_data->scale *= 0.9;
	else if (keycode == XK_t)
		mlx->map_data->rotate += 0.1;
	else if (keycode == XK_g)
		mlx->map_data->rotate -= 0.1;
	else
		return (1);
	return (0);
}

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(mlx->mlx_ptr);
		return (0);
	}
	else if (keycode == XK_minus)
		mlx->map_data->z_factor -= 0.1;
	else if (keycode == XK_equal)
		mlx->map_data->z_factor += 0.1;
	else if (keycode == XK_s)
		mlx->map_data->y_center += 3;
	else if (keycode == XK_w)
		mlx->map_data->y_center -= 3;
	else if (keycode == XK_a)
		mlx->map_data->x_center -= 3;
	else if (keycode == XK_d)
		mlx->map_data->x_center += 3;
	else
		if (handle_key2(keycode, mlx) == 1)
			return (0);
	render_map(mlx->map_data);
	display_map(mlx);
	(void)mlx;
	return (0);
}
