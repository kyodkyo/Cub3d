/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:27:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/06 23:28:00 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_cub *cub)
{
	free(cub->color);
	free(cub->player);
	free(cub->image);
	mlx_destroy_window(cub->mlx, cub->window);
	exit(0);
}

int	play_game(int keycode, t_cub *cub)
{
}
