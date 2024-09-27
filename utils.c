/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:34:06 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/27 12:54:01 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	free_2d_arr(char **str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (flag);
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
