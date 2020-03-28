/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:51:45 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 00:50:42 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_left_right(t_cub *cub, int x, int y)
{
	int n;
	int l;
	int r;

	r = 0;
	l = 0;
	n = y;
	while (y >= 0)
	{
		if (cub->map[x][y] == '1' || cub->map[x][y] == ' ')
			l = 1;
		y--;
	}
	y = n;
	while (cub->map[x][y])
	{
		if (cub->map[x][y] == '1' || cub->map[x][y] == ' ')
			r = 1;
		y++;
	}
	return (l && r);
}

static int	check_top_bottom(t_cub *cub, int x, int y)
{
	int n;
	int b;
	int t;

	b = 0;
	t = 0;
	n = x;
	while (x >= 0 && y < (int)ft_strlen(cub->map[x]))
	{
		if (cub->map[x][y] == '1' || cub->map[x][y] == ' ')
			t = 1;
		x--;
	}
	x = n;
	while (cub->map[x] && y < (int)ft_strlen(cub->map[x]))
	{
		if (cub->map[x][y] == '1' || cub->map[x][y] == ' ')
			b = 1;
		x++;
	}
	return (b && t);
}

static int	check_spaces(t_cub *cub, int x, int y)
{
	int t;
	int b;
	int r;
	int l;

	if (cub->map[x][y] != ' ')
		return (1);
	t = 0;
	b = 0;
	r = 0;
	l = 0;
	if (!y || cub->map[x][y - 1] == '1' || cub->map[x][y - 1] == ' ')
			l = 1;
	if (!x || cub->map[x - 1][y] == '1' || cub->map[x - 1][y] == ' ')
			t = 1;
	if (!cub->map[x][y + 1]
		|| cub->map[x][y + 1] == '1' || cub->map[x][y + 1] == ' ')
			r = 1;
	if (!cub->map[x + 1]
		|| cub->map[x + 1][y] == '1' || cub->map[x + 1][y] == ' ')
			b = 1;
	return (t && b && l && r);
}

int			check_case(t_cub *cub, int x, int y)
{
	int a;
	int b;
	int c;

	a = check_top_bottom(cub, x, y);
	b = check_left_right(cub, x, y);
	c = check_spaces(cub, x, y);
	return (a && b && c);
}