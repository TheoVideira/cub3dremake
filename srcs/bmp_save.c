/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:05:09 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 18:08:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		write_fileheader(int fd, t_cub *cub)
{
	t_fileheader	fh;

	ft_bzero(&fh, sizeof(t_fileheader));
	fh.id = 19778;
	fh.size = 54 + cub->width * cub->height * 3;
	fh.reserved = 0;
	fh.offset = 54;
	if (
		write(fd, &fh.id, 2) == -1 ||
		write(fd, &fh.size, 4) == -1 ||
		write(fd, &fh.reserved, 4) == -1 ||
		write(fd, &fh.offset, 4) == -1)
		return (-1);
	return (0);
}

int		write_dibheader(int fd, t_cub *cub)
{
	t_dibheader		dib;

	ft_bzero(&dib, sizeof(t_dibheader));
	dib.headersize = sizeof(t_dibheader);
	dib.width = cub->width;
	dib.height = cub->height;
	dib.pane = 1;
	dib.bitcount = 24;
	if (
		write(fd, &dib.headersize, 4) == -1 ||
		write(fd, &dib.width, 4) == -1 ||
		write(fd, &dib.height, 4) == -1 ||
		write(fd, &dib.pane, 2) == -1 ||
		write(fd, &dib.bitcount, 2) == -1 ||
		write(fd, &dib.offset, 24) == -1)
		return (-1);
	return (0);
}

int		write_pixeldata(int fd, t_cub *cub)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;
	unsigned char	*tab;

	if (!(tab = malloc(3 * cub->width * cub->height)))
		return (-1);
	i = 0;
	y = cub->height;
	while (--y > 0)
	{
		x = 0;
		while ((int)x < cub->width)
		{
			tab[i * 3] = cub->screen[x + y * cub->width] >> 0;
			tab[i * 3 + 1] = cub->screen[x + y * cub->width] >> 8;
			tab[i * 3 + 2] = cub->screen[x + y * cub->width] >> 16;
			i++;
			x++;
		}
	}
	if (write(fd, tab, 3 * cub->width * cub->height) == -1)
		return (-1);
	free(tab);
	return (0);
}

int		write_bmp(t_cub *cub, char *filename)
{
	int				fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_error("Error while saving screenshot\n", cub);
	if (write_fileheader(fd, cub) == -1)
		ft_error("Error while saving screenshot\n", cub);
	if (write_dibheader(fd, cub) == -1)
		ft_error("Error while saving screenshot\n", cub);
	if (write_pixeldata(fd, cub) == -1)
		ft_error("Error while saving screenshot\n", cub);
	ft_free_all(cub);
	exit(0);
	return (0);
}
