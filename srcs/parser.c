/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:22:39 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/13 00:22:05 by tvideira         ###   ########.fr       */
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

void get_info(char *filename, t_cub *cub)
{
	int fd;
	int gnl;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (is_identifier(line))
			parse_line(line, cub);
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}

int		parse_cub_file(t_cub *cub, int ac, char **av)
{
	init_cub(cub);
	parse_args(ac, av, cub);
	check_cub_file(cub->cub_file_path);
	check_lines(cub->cub_file_path);
	check_map(cub->cub_file_path, cub);
	get_info(cub->cub_file_path, cub);
	check_info(cub);
	parse_map(cub->cub_file_path, cub);
	get_sprite(cub);
	return (0);
}


#include <stdio.h>

int		test(int ac, char **av)
{
	t_cub cub;

	parse_cub_file(&cub, ac, av);
	printf("resolution = %d, %d\n", cub.width, cub.height);
	printf("ceil = r[%d], g[%d], b[%d]\n", cub.c_color[0], cub.c_color[1], cub.c_color[2]);
	printf("floor = r[%d], g[%d], b[%d]\n", cub.f_color[0], cub.f_color[1], cub.f_color[2]);
	printf("path[0] = %s\n", cub.path[0]);
	printf("path[1] = %s\n", cub.path[1]);
	printf("path[2] = %s\n", cub.path[2]);
	printf("path[3] = %s\n", cub.path[3]);
	printf("path[4] = %s\n", cub.path[4]);
	printf("\nMap :\n");
	for (int i = 0; cub.map[i]; i++)
		printf("%s\n", cub.map[i]);
	printf("\nPlayer angle = %f\n", cub.angle);
	printf("Player pos x = %f\n", cub.pos_x);
	printf("Player pos y = %f\n", cub.pos_y);
	for (int i = 0; i < cub.n_sp; i++)
		printf("Sprite no %d, x = %d, y = %d\n", i, cub.sp_x[i], cub.sp_y[i]);
	return (1);
}
/*
int		main(int ac, char **av)
{
	printf("%d\n", (int)0.99999999);
	test(ac, av);
	return (0);
}*/
