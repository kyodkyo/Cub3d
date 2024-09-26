/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:58 by dakang            #+#    #+#             */
/*   Updated: 2024/09/26 19:55:19 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
