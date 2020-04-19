/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 05:04:07 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/19 18:37:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop_hook(t_cub *cub)
{
	render(cub);
	return (0);
}

int		init_screen(t_cub *cub)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	cub->img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->screen = (int *)mlx_get_data_addr(cub->img,
				&bits_per_pixel, &size_line, &endian);
	if (endian != 0 || bits_per_pixel != 32)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cub			cub;

	parse_cub_file(&cub, argc, argv);
	if (!init_screen(&cub) || !init_textures(&cub, -1))
		return (-1);
	if (!(cub.window = mlx_new_window(cub.mlx_ptr,
		cub.width, cub.height, "cub3D")))
		return (-1);
	if (cub.bmp == 1)
	{
		render(&cub);
		write_bmp(&cub, "save.bmp");
	}
	mlx_hook(cub.window, KEYPRESS, 1L << 0, key_press, &cub);
	mlx_hook(cub.window, KEYRELEASE, 1L << 1, key_release, &cub);
	mlx_hook(cub.window, DESTROYNOTIFY, 1L << 17, quit_window, &cub);
	mlx_loop_hook(cub.mlx_ptr, loop_hook, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}
