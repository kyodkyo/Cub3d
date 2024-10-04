/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:53:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/04 21:45:11 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_color(t_cub *cub)
{
	int	w;
	int	h;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT / 2)
		{
			cub->buf[h][w] = cub->color->c_color;
			cub->buf[HEIGHT - h - 1][w] = cub->color->f_color;
			h++;
		}
		w++;
	}
}

void	raycasting(t_cub *cub)
{
	int		i;
	t_dda	dda;
	t_ray	ray;

	i = 0;
	while (i < WIDTH)
	{
		init_dda_ray(cub, &dda, &ray, i);
		run_dda(cub, &dda);
		i++;
	}
}

void	execute(t_cub *cub)
{
	fill_color(cub);
	raycasting(cub);
	// draw_cub();
	// mlx_hook(game->win, 2, 0, &update_frame, game);
	// mlx_hook(game->win, 17, 0, &destroy_win, game);
	// mlx_loop(cub->mlx);
}
