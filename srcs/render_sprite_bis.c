/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:37:49 by marvin            #+#    #+#             */
/*   Updated: 2020/04/20 03:14:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sprite_1(t_cub *cub, int i)
{
	cub->sprite_x = cub->sp_x[i] + 0.5 - cub->pos_x;
	cub->sprite_y = cub->sp_y[i] + 0.5 - cub->pos_y;
	cub->inv_det = 1.0 / (cub->plane_x * cub->dir_y - cub->dir_x *
		cub->plane_y);
	cub->transform_x = cub->inv_det * (cub->dir_y * cub->sprite_x - cub->dir_x
		* cub->sprite_y);
	cub->transform_y = cub->inv_det * (-cub->plane_y * cub->sprite_x
		+ cub->plane_x * cub->sprite_y);
	cub->sprite_screen_x = (int)((cub->width / 2) * (1 + cub->transform_x /
		cub->transform_y));
	cub->sprite_height = abs((int)(cub->height / cub->transform_y));
	cub->draw_start_y = -cub->sprite_height / 2 + cub->height / 2;
	if (cub->draw_start_y < 0)
		cub->draw_start_y = 0;
	cub->draw_end_y = cub->sprite_height / 2 + cub->height / 2;
	if (cub->draw_end_y >= cub->height)
		cub->draw_end_y = cub->height - 1;
	cub->sprite_width = abs((int)(cub->height / cub->transform_y));
	cub->draw_start_x = -cub->sprite_width / 2 + cub->sprite_screen_x;
	if (cub->draw_start_x < 0)
		cub->draw_start_x = 0;
	cub->draw_end_x = cub->sprite_width / 2 + cub->sprite_screen_x;
	if (cub->draw_end_x >= cub->width)
		cub->draw_end_x = cub->width - 1;
}

void	render_sprite_2(t_cub *cub, int s, double *z_buffer)
{
	int t;
	int d;
	int tex_y;
	int pix_screen;
	int pix_tex;

	cub->tex_x = (int)(256 * (s - (-cub->sprite_width / 2 +
		cub->sprite_screen_x)) * cub->tex_w[4] / cub->sprite_width) / 256;
	if (cub->transform_y > 0 && s > 0 && s < cub->width &&
		cub->transform_y < z_buffer[s])
	{
		t = cub->draw_start_y - 1;
		while (++t < cub->draw_end_y)
		{
			d = t * 256 - cub->height * 128 + cub->sprite_height * 128;
			tex_y = ((d * cub->tex_h[4]) / cub->sprite_height) / 256;
			pix_screen = t * cub->width + s;
			pix_tex = cub->tex_w[4] * tex_y + cub->tex_x;
			if (!(!(cub->data[4][pix_tex] & 0x00FFFFFF)))
				cub->screen[pix_screen] = cub->data[4][pix_tex];
		}
	}
}
