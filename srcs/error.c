/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:20:00 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/22 03:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(t_cub *cub)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		free(cub->path[i]);
		if (cub->mlx_ptr)
			if (cub->ptr[i])
				mlx_destroy_image(cub->mlx_ptr, cub->ptr[i]);
	}
	ft_emergency_split(cub->map);
	free(cub->sp_x);
	free(cub->sp_y);
	free(cub->sp_dist);
	if (cub->mlx_ptr)
	{
		if (cub->img)
			mlx_destroy_image(cub->mlx_ptr, cub->img);
		if (cub->window)
			mlx_destroy_window(cub->mlx_ptr, cub->window);
		free(cub->mlx_ptr);
	}
}

void	ft_error(char *error, t_cub *cub)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	ft_free_all(cub);
	exit(-1);
}

void	ft_error_line(char *error, int n, t_cub *cub)
{
	write(2, "Error\n", 6);
	write(2, "Line ", 5);
	ft_putnbr_fd(n, 2);
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	ft_free_all(cub);
	exit(-1);
}

void	ft_error_no(int err, t_cub *cub)
{
	char *error;

	error = strerror(err);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	ft_free_all(cub);
	exit(-1);
}
