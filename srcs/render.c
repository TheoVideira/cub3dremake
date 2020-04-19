/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 05:26:26 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 17:51:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_player_vector(t_cub *cub)
{
	cub->dir_x = cos(cub->angle);
	cub->dir_y = sin(cub->angle);
	cub->plane_x = -cub->dir_y;
	cub->plane_y = cub->dir_x;
}

static void	create_background(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->width * cub->height / 2)
	{
		cub->screen[i] = cub->c_color[0] << 16;
		cub->screen[i] += cub->c_color[1] << 8;
		cub->screen[i] += cub->c_color[2];
		i++;
	}
	while (i < cub->width * cub->height)
	{
		cub->screen[i] = cub->f_color[0] << 16;
		cub->screen[i] += cub->f_color[1] << 8;
		cub->screen[i] += cub->f_color[2];
		i++;
	}
}

void		render(t_cub *cub)
{
	movement_forward_backward(cub);
	create_background(cub);
	init_player_vector(cub);
	render_wall(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->window, cub->img, 0, 0);
}
