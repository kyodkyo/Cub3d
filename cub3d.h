/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:30:26 by dakang            #+#    #+#             */
/*   Updated: 2024/09/29 23:16:14 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dir;

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
	void	*init;
	char	*path;
	int		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
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
	void		*window;
	int			player_num;
	int			**buf;
	int			map_width;
	int			map_height;
	t_player	*player;
	t_image		*image;
	t_image		img[4];
	t_color		*color;
}	t_cub;


/** parsing */
void	check_color(char *line, int *count, t_cub *cub);
void	check_dir(char *line, int *count, t_cub *cub);
void	init(t_cub *cub, char *file);
void	cub_error(char *str);
int		free_arr(char **str, int flag);
int		check_file(char *str);
void	dir_color_check(char *line, int *count, t_cub *cub);
void	valid_map_check(char *line, char **map, t_cub *cub);
void	check_map(t_cub *cub);
int		is_only_space(char *line);
void	is_valid_wall(char **map);
void	make_map(t_cub *cub);
void	check_map(t_cub *cub);

#endif