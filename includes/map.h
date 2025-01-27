/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:19:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/27 16:43:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <sys/types.h>

typedef union u_color
{
	unsigned int	rgba;
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	opacity;
	};
	unsigned char	arr[4];
}			t_color;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}				t_point;

typedef struct s_data
{
	t_point	**map;
	t_point	**rendered_point;
	size_t	line;
	size_t	col;
}				t_data;

typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	image;
	t_data	*map_data;
}				t_mlx;

#endif
