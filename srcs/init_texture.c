/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 05:15:54 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 12:01:42 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_cub *cub, int i)
{
	int bits_per_pixel;
	int size_line;
	int endian;
	int width;
	int height;

	while (++i < 5)
	{
		if (!(cub->ptr[i] = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->path[i], &width, &height)))
    	    return (0);
   		cub->data[i] = (int *)mlx_get_data_addr(
			   cub->ptr[i], &bits_per_pixel, &size_line, &endian);
		if (endian != 0 || bits_per_pixel != 32)
			return (0);
		cub->tex_w[i] = width;
		cub->tex_h[i] = height;
	}
	return (1);
}