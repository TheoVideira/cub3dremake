/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:33 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/02 14:36:34 by tvideira         ###   ########.fr       */
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
	while(ft_isspace(*line))
		line++;
	if (!check_line(*line, &(cub->resolution[0])))
		return ;
	cub->resolution[0] = ft_atoi(line);
	if (cub->resolution[0] < 1)
		cub->resolution[0] = -2;
	while (ft_isdigit(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	if (!check_line(*line, &(cub->resolution[1])))
		return ;
	cub->resolution[1] = ft_atoi(line);
	if (cub->resolution[1] < 1)
		cub->resolution[1] = -2;
	while (ft_isdigit(*line))
		line++;
	if (*line)
		cub->resolution[1] = -4;
}