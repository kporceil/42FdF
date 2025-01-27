/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:12:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 19:53:26 by kporceil         ###   ########lyon.fr   */
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

int		rendering_map(t_data *map_data);
void	apply_translation(t_data *map_data, int dx, int dy, int dz);
int		create_window_and_render(t_data *map_data);
void	apply_zoom(t_data *map_data, float scale);
void	render_points_to_image(t_mlx *mlx);
void	isometric_projection(t_data *map_data);

#endif
