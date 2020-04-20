/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:29:05 by marvin            #+#    #+#             */
/*   Updated: 2020/04/20 03:08:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_wall_4(t_cub *cub)
{
	if (!cub->side)
	{
		cub->perp_wall_dist = (cub->map_x - cub->pos_x + (1.0 - cub->step_x)
			/ 2.0) / cub->ray_dir_x;
		cub->tex_id = (cub->step_x < 0) ? 3 : 2;
		cub->wall_x = cub->pos_y + cub->perp_wall_dist * cub->ray_dir_y;
	}
	else
	{
		cub->perp_wall_dist = (cub->map_y - cub->pos_y + (1.0 - cub->step_y)
			/ 2.0) / cub->ray_dir_y;
		cub->tex_id = (cub->step_y < 0) ? 1 : 0;
		cub->wall_x = cub->pos_x + cub->perp_wall_dist * cub->ray_dir_x;
	}
	cub->wall_x -= floor(cub->wall_x);
}

void	render_wall_5(t_cub *cub)
{
	cub->line_height = (int)(cub->height / cub->perp_wall_dist);
	cub->draw_start = cub->height / 2 - cub->line_height / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->height / 2 + cub->line_height / 2;
	if (cub->draw_end >= cub->height)
		cub->draw_end = cub->height - 1;
	cub->tex_x = (int)(cub->wall_x * cub->tex_w[cub->tex_id]);
	if ((!cub->side && cub->ray_dir_x > 0) || (cub->side && cub->ray_dir_y < 0))
		cub->tex_x = cub->tex_w[cub->tex_id] - cub->tex_x - 1;
	cub->step = 1.0 * cub->tex_h[cub->tex_id] / cub->line_height;
	cub->tex_pos = (cub->draw_start - cub->height / 2 + cub->line_height / 2)
		* cub->step;
}

void	render_wall_6(t_cub *cub, int x)
{
	int y;
	int tex_y;
	int pix_screen;
	int pix_tex;

	y = cub->draw_start - 1;
	while (++y < cub->draw_end)
	{
		tex_y = (int)cub->tex_pos & (cub->tex_h[cub->tex_id] - 1);
		cub->tex_pos += cub->step;
		pix_screen = y * cub->width + x;
		pix_tex = tex_y * cub->tex_h[cub->tex_id] + cub->tex_x;
		cub->screen[pix_screen] = cub->data[cub->tex_id][pix_tex];
	}
}
