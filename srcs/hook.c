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

void	handle_destroy(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
}

void	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_loop_end(mlx->mlx_ptr);
		return ;
	}
	else if (keycode == 45)
		mlx->map_data->z_factor -= 0.1;
	else if (keycode == 61)
		mlx->map_data->z_factor += 0.1;
	else if (keycode == 115)
		mlx->map_data->y_center += 3;
	else if (keycode == 119)
		mlx->map_data->y_center -= 3;
	else if (keycode == 97)
		mlx->map_data->x_center -= 3;
	else if (keycode == 100)
		mlx->map_data->x_center += 3;
	else if (keycode == 114)
		mlx->map_data->scale += 0.5;
	else if (keycode == 102)
		mlx->map_data->scale -= 0.5;
	render_map(mlx->map_data);
	display_map(mlx);
	(void)mlx;
}
