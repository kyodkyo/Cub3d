/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:30:26 by dakang            #+#    #+#             */
/*   Updated: 2024/09/27 12:33:31 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x; // 카메라 평면의 X축 좌표
	double	plane_y; // 카메라 평면의 Y축 좌표
}	t_player;

typedef struct s_image
{
	char	*path;
	int		width;
	int		height;
}	t_image;

typedef struct s_color
{
	int				ceil[3];
	int				ceil_flag;
	unsigned int	c_color;
	int				floor[3];
	int				floor_flag;
	unsigned int	f_color;
}	t_color;

typedef struct s_cub
{
	int			fd;
	char		*map;
	char		**map_arr;
	void		*mlx;
	void		*win;
	int			player_num;
	int			**buf;
	int			map_width;
	int			map_height;
	t_player	*player;
	t_image		*img;
	t_image		img[4];
	t_color		*color;
}	t_cub;

#endif