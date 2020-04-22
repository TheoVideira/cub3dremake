/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:22:39 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/22 04:35:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_identifier(char *str)
{
	if (!str[0])
		return (0);
	if (!str[1] || ft_isspace(str[1]))
		if (str[0] == 'R' || str[0] == 'S' || str[0] == 'F' || str[0] == 'C')
			return (1);
	if (str[0] == 'N' && str[1] == 'O' && (!str[2] || ft_isspace(str[2])))
		return (1);
	if (str[0] == 'S' && str[1] == 'O' && (!str[2] || ft_isspace(str[2])))
		return (1);
	if (str[0] == 'E' && str[1] == 'A' && (!str[2] || ft_isspace(str[2])))
		return (1);
	if (str[0] == 'W' && str[1] == 'E' && (!str[2] || ft_isspace(str[2])))
		return (1);
	return (0);
}

void	parse_line(char *str, t_cub *cub)
{
	if (!str[1] || str[1] == ' ' || str[1] == '\t')
	{
		if (str[0] == 'R')
			parse_res(str, cub);
		if (str[0] == 'S')
			parse_sprite(str, cub);
		if (str[0] == 'F')
			parse_f_color(str, cub);
		if (str[0] == 'C')
			parse_c_color(str, cub);
	}
	if (str[0] == 'N' && str[1] == 'O')
		parse_north(str, cub);
	if (str[0] == 'S' && str[1] == 'O')
		parse_south(str, cub);
	if (str[0] == 'E' && str[1] == 'A')
		parse_east(str, cub);
	if (str[0] == 'W' && str[1] == 'E')
		parse_west(str, cub);
}

void	get_info(char *filename, t_cub *cub)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (is_identifier(line))
			parse_line(line, cub);
		free(line);
		if (!gnl)
			break ;
	}
	close(fd);
}

int		parse_cub_file(t_cub *cub, int ac, char **av)
{
	int x;
	int y;

	init_cub(cub);
	parse_args(ac, av, cub);
	check_cub_file(cub);
	check_lines(cub);
	check_map(cub->cub_file_path, cub);
	get_info(cub->cub_file_path, cub);
	check_info(cub);
	parse_map(cub->cub_file_path, cub);
	get_sprite(cub);
	mlx_get_screen_size(cub->mlx_ptr, &x, &y);
	cub->width = (x < cub->width) ? x : cub->width;
	cub->height = (y < cub->height) ? y : cub->height;
	return (0);
}
