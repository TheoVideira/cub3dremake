/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:57 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 17:38:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_emergency(int fd, char **line)
{
	free(*line);
	close(fd);
}

void		check_map_1(char *filename, t_cub *cub)
{
	int		fd;
	int		gnl;
	char	*line;
	int		inmap;

	inmap = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if ((*line == '1' || *line == ' ') && !inmap)
		{
			cub->no_map++;
			inmap = 1;
		}
		if (!(*line == '1' || *line == ' '))
			inmap = 0;
		free(line);
		if (!gnl)
			break ;
	}
	close(fd);
}

void		check_map_2(t_cub *cub)
{
	int		fd;
	int		gnl;
	char	*line;
	int		found_map;
	int		n;

	n = 0;
	found_map = 0;
	fd = open(cub->cub_file_path, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno, cub);
	while ((gnl = get_next_line(fd, &line)) > -1 && (++n))
	{
		if ((*line == ' ' || *line == '1'))
			found_map = 1;
		if (is_identifier(line) && found_map)
		{
			ft_emergency(fd, &line);
			ft_error_line("Map should be last elment of file", n, cub);
		}
		free(line);
		if (!gnl)
			break ;
	}
	close(fd);
}
