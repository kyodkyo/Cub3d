/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:27:17 by dakang            #+#    #+#             */
/*   Updated: 2024/09/29 16:58:36 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char const *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char *temp, char const *buffer)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen_gnl(temp) + ft_strlen_gnl(buffer);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (*temp)
		res[i++] = *temp++;
	while (*buffer)
		res[i++] = *buffer++;
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *str, int start, int end)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen_gnl(str);
	if (str == NULL)
	{
		res = ft_strdup("");
		if (res == NULL)
			return (NULL);
		return (res);
	}
	if (len <= end || len - start < end)
		end = len - start;
	res = (char *)malloc(sizeof(char) * (end + 1));
	if (res == NULL)
		return (NULL);
	while (i < end && start + i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
