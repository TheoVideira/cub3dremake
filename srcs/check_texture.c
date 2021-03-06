/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:33:19 by marvin            #+#    #+#             */
/*   Updated: 2020/04/19 17:33:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_no_tex(t_cub *cub)
{
	int fd;

	if (cub->no == 0)
		ft_error("Missing north texture\n", cub);
	if (cub->no != 1)
		ft_error("North texture appeared mutliple times\n", cub);
	fd = open(cub->path[0], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNorth texture : ", 22);
		ft_error_no(errno, cub);
	}
	if (check_format(cub->path[0], ".xpm"))
	{
		close(fd);
		ft_error("North texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_so_tex(t_cub *cub)
{
	int fd;

	if (cub->so == 0)
		ft_error("Missing south texture\n", cub);
	if (cub->so != 1)
		ft_error("South texture appeared mutliple times\n", cub);
	fd = open(cub->path[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nSouth texture : ", 22);
		ft_error_no(errno, cub);
	}
	if (check_format(cub->path[1], ".xpm"))
	{
		close(fd);
		ft_error("South texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_ea_tex(t_cub *cub)
{
	int fd;

	if (cub->ea == 0)
		ft_error("Missing ea texture\n", cub);
	if (cub->ea != 1)
		ft_error("East texture appeared mutliple times\n", cub);
	fd = open(cub->path[2], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nEast texture : ", 21);
		ft_error_no(errno, cub);
	}
	if (check_format(cub->path[2], ".xpm"))
	{
		close(fd);
		ft_error("East texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_we_tex(t_cub *cub)
{
	int fd;

	if (cub->we == 0)
		ft_error("Missing west texture\n", cub);
	if (cub->we != 1)
		ft_error("West texture appeared mutliple times\n", cub);
	fd = open(cub->path[3], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nWest texture : ", 21);
		ft_error_no(errno, cub);
	}
	if (check_format(cub->path[3], ".xpm"))
	{
		close(fd);
		ft_error("West texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_sp_tex(t_cub *cub)
{
	int fd;

	if (cub->s == 0)
		ft_error("Missing sprite texture\n", cub);
	if (cub->s != 1)
		ft_error("Sprite texture appeared mutliple times\n", cub);
	fd = open(cub->path[4], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nSprite texture : ", 23);
		ft_error_no(errno, cub);
	}
	if (check_format(cub->path[4], ".xpm"))
	{
		close(fd);
		ft_error("Sprite texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}
