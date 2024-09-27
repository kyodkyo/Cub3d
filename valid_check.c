/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:53:42 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/27 13:05:45 by dakyo            ###   ########.fr       */
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
		return (free_2d_arr(tmp, 1));
	if (!(tmp[count][len - 4] == '.' && tmp[count][len - 3] == 'c'
		&& tmp[count][len - 2] == 'u' && tmp[count][len - 1] == 'b'))
		return (free_2d_arr(tmp, 1));
	return (free_2d_arr(tmp, 0));
}

void	check_dir()
{
	
}

void check_color()
{
	
}

void	dir_color_check(char *line, int *count, t_cub *cub)
{
	char	**tmp;

	if (line[0] == '\n' && !(line[1]))
		return ;
	if (is_space(line))
		printf("only space error\n");
	tmp = ft_split(line, ' ');
	if (!tmp)
		printf("split error\n");
	if (!(ft_strncmp(tmp[0], "EA", 2)) || !(ft_strncmp(tmp[0], "WE", 2))
		|| !(ft_strncmp(tmp[0], "SO", 2)) || !(ft_strncmp(tmp[0], "NO", 2)))
		check_dir(line, count, cub);
	else if (!(ft_strncmp(tmp[0], "C", 1)) || !(ft_strncmp(tmp[0], "F", 1)))
		check_color(line, count, cub);
	else
		printf("unknown dir or color\n");
	free_2d_arr(tmp, 0);
}

int	is_valid_value(char *line, t_cub *cub)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == ' ' || line[i] == '\n')
			continue ;
		else if (line[i] == 'E' || line[i] == 'W'
			|| line[i] == 'S' || line[i] == 'N')
			cub->player_num++;
		else
			return (0);
		i++;
	}
	retunr (1);
}

void	valid_map_check(char *line, char **map, t_cub *cub)
{
	char	*tmp;

	tmp = *map;
	if (is_valid_vlaue(line, cub))
		*map = ft_strjoin(tmp, line, ft_strlen(line), ft_strlen(tmp));
	else
	{
		free(line);
		free(*map);
		printf("invalid value in map\n");
	}
}
