/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:21 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/22 04:31:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_heigth(char *filename, t_cub *cub)
{
	int		fd;
	int		gnl;
	char	*line;
	int		height;

	height = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (*line == '1' || *line == ' ')
			height++;
		free(line);
		if (!gnl)
			break ;
	}
	if (!(cub->map = malloc(sizeof(char *) * height)))
		ft_error("malloc error\n", cub);
	while (--height >= 0)
		cub->map[height] = NULL;
	close(fd);
}

void	get_map(char *filename, t_cub *cub)
{
	int		fd;
	int		gnl;
	char	*line;
	int		n;

	n = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (*line == '1' || *line == ' ')
		{
			create_line_map(line, cub, n);
			n++;
		}
		free(line);
		if (!gnl)
			break ;
	}
	close(fd);
}

void	valid_case_player_pos_check(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (!is_valid_case(cub->map[i][j]))
				ft_error("Map contains invalid value\n", cub);
			if (is_pos_case(cub->map[i][j]))
				init_player_values(cub->map[i][j], cub, j, i);
		}
	}
	if (cub->angle == -1.0)
		ft_error("Map is missing player position\n", cub);
}

void	check_closed_map(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if ((!check_case(cub, i, j)))
				ft_error("Map isn't closed\n", cub);
		}
	}
}

void	parse_map(char *filename, t_cub *cub)
{
	get_map_heigth(filename, cub);
	get_map(filename, cub);
	valid_case_player_pos_check(cub);
	check_closed_map(cub);
}
