/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:02:55 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 17:43:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_args(int ac, char **av, t_cub *cub)
{
	if (ac < 2)
		ft_error("Too few arguments", cub);
	if (ac > 3)
		ft_error("Too much arguments", cub);
	cub->cub_file_path = av[1];
	if (ac == 3)
		if (strncmp("--save", av[2], ft_strlen("--save")))
			ft_error("Second argument must be '--save'", cub);
		else
			cub->bmp = 1;
	else
		cub->bmp = 0;
}
