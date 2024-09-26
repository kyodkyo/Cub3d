/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:54:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/26 20:27:47 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub, char *file)
{
	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		printf("file open error\n");
	cub->map = NULL;
	cub->map_arr = NULL;
	cub->player_num = 0;
	cub->player = (t_player *)malloc(sizeof(t_player));
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
		printf("mlx init error\n");
	save_map(cub);
	if (!cub->map)
		printf("map error\n");
	//check_map();
}
