/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:33 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 17:48:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line(char line, int *p)
{
	if (!line)
		return (0);
	if (!ft_isdigit(line))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

void		parse_res(char *line, t_cub *cub)
{
	cub->r++;
	line++;
	while (ft_isspace(*line))
		line++;
	if (!check_line(*line, &(cub->width)))
		return ;
	cub->width = ft_atoi(line);
	if (cub->width < 1)
		cub->width = -2;
	while (ft_isdigit(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	if (!check_line(*line, &(cub->height)))
		return ;
	cub->height = ft_atoi(line);
	if (cub->height < 1)
		cub->height = -2;
	while (ft_isdigit(*line))
		line++;
	if (*line)
		cub->height = -4;
}
