/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:53:42 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/26 20:27:03 by dakyo            ###   ########.fr       */
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

int	is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}


void	dir_color_check(char *line, int *count, t_cub *cub)
{
	char	**tmp;

	if (line[0] == '\n' && !(line[1]))
		return ;
	if (is_space(line))
		printf("is space error\n");
	tmp = ft_split(line, ' ');
	if (!tmp)
		printf("split error\n");
	//dir : EA, WE, SO, NO
	//color : F, C
	//free
}

void	valid_map_check()
{
	
}