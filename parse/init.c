/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:54:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/29 16:56:20 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cub(t_cub *cub, char *file)
{
	int	i;

	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		cub_error("file open error\n");
	cub->map = NULL;
	cub->map_arr = NULL;
	cub->player_num = 0;
	cub->player = (t_player *)malloc(sizeof(t_player));
	cub->image = (t_image *)malloc(sizeof(t_image));
	cub->color = (t_color *)malloc(sizeof(t_color));
	if (!cub->player || !cub->image || !cub->color)
		cub_error("malloc error");
	cub->map_width = 0;
	cub->map_height = 0;
	cub->color->ceil_flag = 0;
	cub->color->floor_flag = 0;
	i = 0;
	while (i < 4)
	{
		cub->img[i].init = NULL;
		cub->img[i].path = NULL;
		cub->img[i].data = NULL;
		i++;
	}
}

void	save_map(t_cub *cub)
{
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
			break ;
		if (count < 6)
			dir_color_check(line, &count, cub);
		else
			valid_map_check(line, &cub->map, cub);
		free(line);
	}
	close(cub->fd);
	free(line);
}

void	init(t_cub *cub, char *file)
{
	init_cub(cub, file);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		cub_error("mlx init error");
	save_map(cub);
	if (!cub->map)
		cub_error("map error");
	//check_map();
}
