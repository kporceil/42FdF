/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:12:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/02/09 15:33:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "map.h"

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1920
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1080
# endif

void	apply_translation(t_data *map_data);
int		init_mlx(t_mlx *mlx, t_data *map_data);
void	display_map(t_mlx *mlx);
void	render_points_to_image(t_mlx *mlx);
void	change_z(t_data *map_data, int factor);
void	render_map(t_data *map_data);
void	rotate_x(int *x, int *y, int *z, t_data *map);
void	rotate_y(int *x, int *z, t_data *map);
void	rotate_z(int *x, int *y, t_data *map);

#endif
