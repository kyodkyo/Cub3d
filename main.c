/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:58 by dakang            #+#    #+#             */
/*   Updated: 2024/09/25 21:10:02 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *str)
{
	int		len;
	int		count;
	char	**tmp;

	tmp = ft_split(str, '/');
	if (!tmp)
		printf("split error\n");
	count = -1;
	while (tmp[count])
		count++;
	len = ft_strlen(tmp[count]);
	if (len <= 4)
		return (free_2d(tmp, 1));
	if (!(tmp[count][len - 4] == '.' && tmp[count][len - 3] == 'c'
		&& tmp[count][len - 2] == 'u' && tmp[count][len - 1] == 'b'))
		return (free_2d(tmp, 1));
	return (free_2d(tmp, 0));
}

void	init_cub(t_cub *cub, char *file)
{
	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		printf("file open error\n");
	
}

void	init(t_cub *cub, char *file)
{
	init_cub(cub, file);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		printf("mlx init error\n");
	//save_map(cub);
	if (!cub->map)
		printf("map error\n");
	//check_map();
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		printf("argc error\n");
	if (check_file(argv[1]))
		printf("file error\n");
	init(&cub, argv[1]);
	// execute
}
