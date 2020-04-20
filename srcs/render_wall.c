/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:34:22 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/20 03:10:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_wall_1(t_cub *cub, int x)
{
	cub->camera_x = 2.0 * x / cub->width - 1.0;
	cub->ray_dir_x = cub->dir_x + cub->camera_x * cub->plane_x;
	cub->ray_dir_y = cub->dir_y + cub->camera_x * cub->plane_y;
	cub->map_x = (int)cub->pos_x;
	cub->map_y = (int)cub->pos_y;
	cub->delta_dist_x = fabs(1.0 / cub->ray_dir_x);
	cub->delta_dist_y = fabs(1.0 / cub->ray_dir_y);
}

static void	render_wall_2(t_cub *cub)
{
	if (cub->ray_dir_x < 0)
	{
		cub->step_x = -1;
		cub->side_dist_x = (cub->pos_x - cub->map_x) * cub->delta_dist_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_dist_x = (cub->map_x + 1.0 - cub->pos_x) * cub->delta_dist_x;
	}
	if (cub->ray_dir_y < 0)
	{
		cub->step_y = -1;
		cub->side_dist_y = (cub->pos_y - cub->map_y) * cub->delta_dist_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_dist_y = (cub->map_y + 1.0 - cub->pos_y) * cub->delta_dist_y;
	}
}

static void	render_wall_3(t_cub *cub)
{
	while (cub->map[cub->map_y][cub->map_x] != '1')
	{
		if (cub->side_dist_x < cub->side_dist_y)
		{
			cub->side_dist_x += cub->delta_dist_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->side_dist_y += cub->delta_dist_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
	}
}

void		render_wall(t_cub *cub, double *z_buffer)
{
	int		x;

	x = -1;
	while (++x < cub->width)
	{
		render_wall_1(cub, x);
		render_wall_2(cub);
		render_wall_3(cub);
		render_wall_4(cub);
		render_wall_5(cub);
		render_wall_6(cub, x);
		z_buffer[x] = cub->perp_wall_dist;
	}
}
