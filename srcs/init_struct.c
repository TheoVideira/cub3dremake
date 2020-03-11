/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:48 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 01:19:14 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	init_parse_info(cub);
	init_game_info(cub);
	init_input(cub);
}

void	init_parse_info(t_cub *cub)
{
	cub->r = 0;
	cub->s = 0;
	cub->f = 0;
	cub->c = 0;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->no_map = 0;
}

void	init_game_info(t_cub *cub)
{
	cub->width = -1;
	cub->height = -1;
	cub->f_color[0] = -1;
	cub->f_color[1] = -1;
	cub->f_color[2] = -1;
	cub->c_color[0] = -1;
	cub->c_color[1] = -1;
	cub->c_color[2] = -1;
	cub->path[0] = NULL;
	cub->path[1] = NULL;
	cub->path[2] = NULL;
	cub->path[3] = NULL;
	cub->path[4] = NULL;
	cub->angle = -1.0;
	cub->pos_x = -1.0;
	cub->pos_y = -1.0;
}

void	init_input(t_cub *cub)
{
	cub->key_forward = 0;
	cub->key_backward = 0;
	cub->key_left = 0;
	cub->key_right = 0;
	cub->key_rotate_left = 0;
	cub->key_rotate_right = 0;
}
