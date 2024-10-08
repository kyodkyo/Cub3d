/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:27:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/08 17:35:51 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(t_cub *cub)
{
	free(cub->color);
	free(cub->player);
	free(cub->image);
	mlx_destroy_window(cub->mlx, cub->window);
	exit(0);
}

void	move_player(t_cub *cub, double dx, double dy)
{
	int		cur_x;
	int		cur_y;
	char	**map;

	cur_x = cub->player->pos_x;
	cur_y = cub->player->pos_y;
	map = cub->map_arr;
	if (map[(int)(cur_x + dx)][(int)cur_y] != '1')
		cub->player->pos_x += dx;
	if (map[(int)cur_x][(int)(cur_y + dy)] != '1')
		cub->player->pos_y += dy;
	mlx_clear_window(cub->mlx, cub->window);
	execute(cub);
}

void	rotate_player(t_cub *cub, int dir)
{
	double	angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	angle = ROTATION_SPEED * (M_1_PI / 180.0);
	dir_x = cub->player->dir_x;
	dir_y = cub->player->dir_y;
	plane_x = cub->player->plane_x;
	plane_y = cub->player->plane_y;
	if (dir == 2)
		angle *= -1;
	cub->player->dir_x = cos(angle) * dir_x - sin(angle) * dir_y;
	cub->player->dir_y = sin(angle) * dir_x - cos(angle) * dir_y;
	cub->player->plane_x = cos(angle) * plane_x - sin(angle) * plane_y;
	cub->player->plane_y = sin(angle) * plane_x - cos(angle) * plane_y;
	mlx_clear_window(cub->mlx, cub->window);
	execute(cub);
}

int	play_game(int key, t_cub *cub)
{
	double	t_dir_x;
	double	t_dir_y;
	double	t_plane_x;
	double	t_plane_y;

	t_dir_x = cub->player->dir_x * MOVE_SPEED;
	t_dir_y = cub->player->dir_y * MOVE_SPEED;
	t_plane_x = cub->player->plane_x * MOVE_SPEED;
	t_plane_y = cub->player->plane_y * MOVE_SPEED;
	if (key == ESC)
		close_window(cub);
	else if (key == W)
		move_player(cub, t_dir_x, t_dir_y);
	else if (key == A)
		move_player(cub, -t_plane_x, -t_plane_y);
	else if (key == S)
		move_player(cub, -t_dir_x, -t_dir_y);
	else if (key == D)
		move_player(cub, t_plane_x, t_plane_y);
	else if (key == LEFT)
		rotate_player(cub, 1);
	else if (key == RIGHT)
		rotate_player(cub, 2);
	return (0);
}
