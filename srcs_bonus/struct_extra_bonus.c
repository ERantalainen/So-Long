/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_extra_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:58:57 by erantala          #+#    #+#             */
/*   Updated: 2025/05/21 15:00:26 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	ft_malloc_nbr(t_images	*img)
{
	int	nbr;

	nbr = 0;
	img->nbr_i = malloc(sizeof(mlx_image_t *) * 10);
		if (!img->nbr_i)
			ft_exit(NULL, "Error mallocing struct", NULL);
		while(nbr++ < 9)
		{
			img->nbr_i[nbr] = malloc(sizeof(mlx_image_t));
			if	(!img->nbr_i[nbr])
			{
				ft_free_struct(img->nbr_i, nbr);
				ft_exit(NULL, "Error mallocing struct", NULL);
			}
		}
}