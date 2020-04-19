/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:37:08 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 17:28:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub_file(t_cub *cub)
{
	int fd;

	fd = open(cub->cub_file_path, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	if (check_format(cub->cub_file_path, ".cub"))
	{
		close(fd);
		ft_error("File isn't a .cub file\n", cub);
	}
	close(fd);
}

void	check_lines(t_cub *cub)
{
	int		fd;
	int		gnl;
	int		n;
	char	*line;

	fd = open(cub->cub_file_path, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	n = 0;
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		n++;
		if (*line && (!is_identifier(line) && (*line != '1' && *line != ' ')))
		{
			free(line);
			close(fd);
			ft_error_line("Not empty line that isn't recognized\n", n, cub);
		}
		free(line);
		if (!gnl)
			break ;
	}
	close(fd);
}

void	check_map(char *filename, t_cub *cub)
{
	check_map_1(filename, cub);
	if (cub->no_map == 0)
		ft_error("Map error : No map found", cub);
	if (cub->no_map != 1)
		ft_error("Map error : There should be one map on the file\
		\nHint : remove empty lines in its declaration.\n", cub);
	check_map_2(cub);
}

void	check_info(t_cub *cub)
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
