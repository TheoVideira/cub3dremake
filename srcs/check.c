/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:37:08 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 00:24:19 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_cub_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	if (check_format(filename, ".cub"))
	{
		close(fd);
		ft_error("File isn't a .cub file\n");
	}
	close(fd);
}

void check_lines(char *filename)
{
	int fd;
	int gnl;
	int n;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	n = 0;
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		n++;
		if (*line && (!is_identifier(line) && (*line != '1' && *line != ' ')))
		{
			free(line);
			close(fd);
			ft_error_line("Not empty line that isn't recognized\n", n);			
		}
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}

void check_map(char *filename, t_cub *cub)
{
	check_map_1(filename, cub);
	if (cub->no_map == 0)
		ft_error("Map error : No map found");
	if (cub->no_map != 1)
		ft_error("Map error : There should be one map on the file\
		\nHint : remove empty lines in its declaration.\n");
	check_map_2(filename);
}

void check_info(t_cub *cub)
{
	check_resolution(cub);
	check_f_color(cub);
	check_c_color(cub);
	check_no_tex(cub);
	check_so_tex(cub);
	check_ea_tex(cub);
	check_we_tex(cub);
	check_sp_tex(cub);
}