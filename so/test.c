/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:52:25 by erantala          #+#    #+#             */
/*   Updated: 2025/05/13 13:56:09 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	char **map;
	t_point	path;

	int fd = open("map_one.ber", O_RDONLY);
	if (get_map(fd, map, &path) == -1)
		ft_printf("Fail");
	else
		ft_printf("Success");
	close(fd);
}