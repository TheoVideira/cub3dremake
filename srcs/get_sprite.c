/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:14:34 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 03:42:57 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	how_many_sprite(t_cub *cub)
{
	int x;
	int y;

	cub->n_sp = 0;
	y = -1;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == '2')
				cub->n_sp++;
		}
	}
}

static void	init_sprite(t_cub *cub)
{
	if (!(cub->sp_x = malloc(sizeof(int) * cub->n_sp)))
		ft_error("Malloc failed");
	if (!(cub->sp_y = malloc(sizeof(int) * cub->n_sp)))
	{
		free(cub->sp_x);
		ft_error("Malloc failed");
	}
	if (!(cub->sp_dist = malloc(sizeof(int) * cub->n_sp)))
	{
		free(cub->sp_x);
		free(cub->sp_y);
		ft_error("Malloc failed");
	}

}

static void	pos_sprite(t_cub *cub)
{
	int i;
	int x;
	int y;

	i = 0;
	y = -1;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == '2')
			{
				cub->sp_x[i] = x;
				cub->sp_y[i] = y;
				i++;
			}
		}
	}
}

void		get_sprite(t_cub *cub)
{
	how_many_sprite(cub);
	init_sprite(cub);
	pos_sprite(cub);
}