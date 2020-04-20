/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:29:58 by marvin            #+#    #+#             */
/*   Updated: 2020/04/20 03:16:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_dist(t_cub *cub)
{
	int i;

	i = -1;
	while (++i < cub->n_sp)
		cub->sp_dist[i] = ((cub->pos_x - cub->sp_x[i]) * (cub->pos_x -
			cub->sp_x[i]) + (cub->pos_y - cub->sp_y[i]) * (cub->pos_y -
			cub->sp_y[i]));
}

static void	sort_utils(t_cub *cub, int i)
{
	int tmp;

	tmp = cub->sp_dist[i];
	cub->sp_dist[i] = cub->sp_dist[i + 1];
	cub->sp_dist[i + 1] = tmp;
	tmp = cub->sp_x[i];
	cub->sp_x[i] = cub->sp_x[i + 1];
	cub->sp_x[i + 1] = tmp;
	tmp = cub->sp_y[i];
	cub->sp_y[i] = cub->sp_y[i + 1];
	cub->sp_y[i + 1] = tmp;
}

static void	sort_sprite(t_cub *cub)
{
	int		i;
	int		sort;

	sort = 0;
	sprite_dist(cub);
	while (!sort)
	{
		i = -1;
		sort = 1;
		while (++i < cub->n_sp - 1)
		{
			if (cub->sp_dist[i] < cub->sp_dist[i + 1])
			{
				sort = 0;
				sort_utils(cub, i);
			}
		}
	}
}

void		render_sprite(t_cub *cub, double *z_buffer)
{
	int i;
	int s;

	i = -1;
	sort_sprite(cub);
	while (++i < cub->n_sp)
	{
		render_sprite_1(cub, i);
		s = cub->draw_start_x - 1;
		while (++s < cub->draw_end_x)
		{
			render_sprite_2(cub, s, z_buffer);
		}
	}
}
