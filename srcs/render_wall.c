/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:34:22 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 12:37:38 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_wall(t_cub *cub)
{
	int x = -1;
	while (++x < cub->width)
	{
		double camera_x = 2.0 * x / cub->width - 1.0;
		double ray_dir_x = cub->dir_x + camera_x * cub->plane_x; 
		double ray_dir_y = cub->dir_y + camera_x * cub->plane_y; 

		int map_x = (int)cub->pos_x; 
		int map_y = (int)cub->pos_y; 

		double delta_dist_x = fabs(1.0 / ray_dir_x);
		double delta_dist_y = fabs(1.0 / ray_dir_y);
		
		double side_dist_x, side_dist_y, perp_wall_dist, wall_x;

		int step_x, step_y, side, tex_id;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (cub->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - cub->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (cub->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - cub->pos_y) * delta_dist_y;
		}
		
		while (cub->map[map_y][map_x] != '1')
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
		}
		if (!side)
		{
			perp_wall_dist = (map_x - cub->pos_x + (1.0 - step_x) / 2.0) / ray_dir_x;
			tex_id = (step_x < 0) ? 3 : 2;
			wall_x = cub->pos_y + perp_wall_dist * ray_dir_y;
		}
		else
		{
			perp_wall_dist = (map_y - cub->pos_y + (1.0 - step_y) / 2.0) / ray_dir_y;
			tex_id = (step_y < 0) ? 1 : 0;
			wall_x = cub->pos_x + perp_wall_dist * ray_dir_x;
		}
		wall_x -= floor(wall_x);

		int line_height = (int)(cub->height / perp_wall_dist);

		int draw_start = cub->height / 2 - line_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = cub->height / 2 + line_height / 2;
		if (draw_end >= cub->height)
			draw_end = cub->height - 1;

		int tex_x = (int)(wall_x * cub->tex_w[tex_id]);
		if ((!side && ray_dir_x > 0) || (side && ray_dir_y < 0))
			tex_x = cub->tex_w[tex_id] - tex_x - 1;
		double step = 1.0 * cub->tex_h[tex_id] / line_height;

		double tex_pos = (draw_start - cub->height / 2 + line_height / 2) * step;

		int y = draw_start - 1;
		while (++y < draw_end)
		{
			int tex_y = (int)tex_pos & (cub->tex_h[tex_id] - 1);
			tex_pos += step;
			int pix_screen = y * cub->width + x;
			int pix_tex = tex_y * cub->tex_h[tex_id] + tex_x;
			cub->screen[pix_screen] = cub->data[tex_id][pix_tex];
		}
	}
}