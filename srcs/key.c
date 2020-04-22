/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/22 04:42:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->key_forward = 1;
	if (key == S_KEY)
		cub->key_backward = 1;
	if (key == A_KEY)
		cub->key_left = 1;
	if (key == D_KEY)
		cub->key_right = 1;
	if (key == LEFT_KEY)
		cub->key_rotate_left = 1;
	if (key == RIGHT_KEY)
		cub->key_rotate_right = 1;
	return (1);
}

int		key_release(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->key_forward = 0;
	if (key == S_KEY)
		cub->key_backward = 0;
	if (key == A_KEY)
		cub->key_left = 0;
	if (key == D_KEY)
		cub->key_right = 0;
	if (key == LEFT_KEY)
		cub->key_rotate_left = 0;
	if (key == RIGHT_KEY)
		cub->key_rotate_right = 0;
	if (key == ESC_KEY)
	{
		quit_window(cub);
	}
	return (1);
}

void	movement_forward_backward(t_cub *cub)
{
	int y;
	int x;

	y = (int)(cub->pos_y + cub->dir_y * MOVE_SPEED * 4.0);
	x = (int)(cub->pos_x + cub->dir_x * MOVE_SPEED * 4.0);
	if (cub->key_forward && can_move(cub->map[y][x]))
	{
		cub->pos_x += cub->dir_x * MOVE_SPEED;
		cub->pos_y += cub->dir_y * MOVE_SPEED;
	}
	y = (int)(cub->pos_y - cub->dir_y * MOVE_SPEED * 4.0);
	x = (int)(cub->pos_x - cub->dir_x * MOVE_SPEED * 4.0);
	if (cub->key_backward && can_move(cub->map[y][x]))
	{
		cub->pos_x -= cub->dir_x * MOVE_SPEED;
		cub->pos_y -= cub->dir_y * MOVE_SPEED;
	}
	movement_left_right_rotate(cub);
}

void	movement_left_right_rotate(t_cub *cub)
{
	int y;
	int x;

	y = (int)(cub->pos_y + cub->dir_x * MOVE_SPEED * 4.0);
	x = (int)(cub->pos_x - cub->dir_y * MOVE_SPEED * 4.0);
	if (cub->key_right && can_move(cub->map[y][x]))
	{
		cub->pos_x -= cub->dir_y * MOVE_SPEED;
		cub->pos_y += cub->dir_x * MOVE_SPEED;
	}
	y = (int)(cub->pos_y - cub->dir_x * MOVE_SPEED * 4.0);
	x = (int)(cub->pos_x + cub->dir_y * MOVE_SPEED * 4.0);
	if (cub->key_left && can_move(cub->map[y][x]))
	{
		cub->pos_x += cub->dir_y * MOVE_SPEED;
		cub->pos_y -= cub->dir_x * MOVE_SPEED;
	}
	cub->angle -= (cub->key_rotate_left) ? ROTATE_SPEED : 0;
	cub->angle += (cub->key_rotate_right) ? ROTATE_SPEED : 0;
}

int		quit_window(t_cub *cub)
{
	ft_free_all(cub);
	exit(0);
	return (0);
}
