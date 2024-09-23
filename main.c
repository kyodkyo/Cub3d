/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:58 by dakang            #+#    #+#             */
/*   Updated: 2024/09/23 21:10:54 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_file(char *argv)
{

}

int main(int argc, char **argv)
{
    if (argc != 2)
        printf("argc error\n");
    if (check_file(argv[1]))
        printf("file error\n");
    // parse
    // execute
}
