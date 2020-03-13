/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:13 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/13 06:07:35 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int		is_valid_case(char c)
{
	return ((c >= '0' && c <= '2')
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int		is_pos_case(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int		can_move(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0');
}

void	init_player_values(char c, t_cub *cub, int x, int y)
{
	if (cub->angle != -1.0)
	{
		ft_emergency_split(cub->map);
		ft_error_free("Map error : Player position should appear once\n", cub);
	}
	if (c == 'N')
		cub->angle = M_PI / 2.0;
	else if (c == 'S')
		cub->angle = 3.0 * M_PI / 2.0;
	else if (c == 'E')
		cub->angle = 0.0;
	else
		cub->angle = M_PI;
	cub->pos_x = x + 0.5;
	cub->pos_y = y + 0.5;
}

void	create_line_map(char *line, t_cub *cub, int n)
{
	char	**split;
	int		len;
	int		i;	

	i = -1;
	len = 0;
	split = ft_split(line, ' ');
	while (split[++i])
		len += ft_strlen(split[i]);
	if (!(cub->map[n] = ft_calloc(1, sizeof(char) * len + 1)))
	{
		ft_emergency_split(split);
		ft_emergency_split(cub->map);
		ft_error_free("error during calloc\n", cub);
	}
	i = -1;
	while(split[++i])
		ft_strlcat(cub->map[n], split[i], len + 1);
	ft_emergency_split(split);
}