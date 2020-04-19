/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:22:04 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 17:49:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_north(char *line, t_cub *cub)
{
	cub->no++;
	line += 2;
	while (ft_isspace(*line))
		line++;
	cub->path[0] = ft_strdup(line);
}

void	parse_south(char *line, t_cub *cub)
{
	cub->so++;
	line += 2;
	while (ft_isspace(*line))
		line++;
	cub->path[1] = ft_strdup(line);
}

void	parse_east(char *line, t_cub *cub)
{
	cub->ea++;
	line += 2;
	while (ft_isspace(*line))
		line++;
	cub->path[2] = ft_strdup(line);
}

void	parse_west(char *line, t_cub *cub)
{
	cub->we++;
	line += 2;
	while (ft_isspace(*line))
		line++;
	cub->path[3] = ft_strdup(line);
}

void	parse_sprite(char *line, t_cub *cub)
{
	cub->s++;
	line++;
	while (ft_isspace(*line))
		line++;
	cub->path[4] = ft_strdup(line);
}
