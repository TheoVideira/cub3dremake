#include "cub3d.h"

void	check_no_tex(t_cub *cub)
{
	int fd;

	if (cub->no == 0)
		ft_error_free("Missing north texture\n", cub);
	if (cub->no != 1)
		ft_error_free("North texture appeared mutliple times\n", cub);
	fd = open(cub->path[0], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNorth texture : ", 22);
		ft_error_no_free(errno, cub);
	}
	if (check_format(cub->path[0], ".xpm"))
	{
		close(fd);
		ft_error_free("North texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_so_tex(t_cub *cub)
{
	int fd;

	if (cub->so == 0)
		ft_error_free("Missing south texture\n", cub);
	if (cub->so != 1)
		ft_error_free("South texture appeared mutliple times\n", cub);
	fd = open(cub->path[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nSouth texture : ", 22);
		ft_error_no_free(errno, cub);
	}
	if (check_format(cub->path[1], ".xpm"))
	{
		close(fd);
		ft_error_free("South texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_ea_tex(t_cub *cub)
{
	int fd;

	if (cub->ea == 0)
		ft_error_free("Missing ea texture\n", cub);
	if (cub->ea != 1)
		ft_error_free("East texture appeared mutliple times\n", cub);
	fd = open(cub->path[2], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nEast texture : ", 21);
		ft_error_no_free(errno, cub);
	}
	if (check_format(cub->path[2], ".xpm"))
	{
		close(fd);
		ft_error_free("East texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_we_tex(t_cub *cub)
{
	int fd;

	if (cub->we == 0)
		ft_error_free("Missing west texture\n", cub);
	if (cub->we != 1)
		ft_error_free("West texture appeared mutliple times\n", cub);
	fd = open(cub->path[3], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nWest texture : ", 21);
		ft_error_no_free(errno, cub);
	}
	if (check_format(cub->path[3], ".xpm"))
	{
		close(fd);
		ft_error_free("West texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}

void	check_sp_tex(t_cub *cub)
{
	int fd;

	if (cub->s == 0)
		ft_error_free("Missing sprite texture\n", cub);
	if (cub->s != 1)
		ft_error_free("Sprite texture appeared mutliple times\n", cub);
	fd = open(cub->path[4], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nSprite texture : ", 23);
		ft_error_no_free(errno, cub);
	}
	if (check_format(cub->path[4], ".xpm"))
	{
		close(fd);
		ft_error_free("Sprite texture file isn't a .xpm file\n", cub);
	}
	close(fd);
}