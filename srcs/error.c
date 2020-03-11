/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:20:00 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/11 00:59:14 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(-1);
}

void	ft_error_free(char *error, t_cub *cub)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	free(cub->path[0]);
	free(cub->path[1]);
	free(cub->path[2]);
	free(cub->path[3]);
	free(cub->path[4]);
	exit(-1);
}


void	ft_error_line(char *error, int n)
{
	write(2, "Error\n", 6);
	write(2, "Line ", 5);
	ft_putnbr_fd(n, 2);
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	exit(-1);
}

void	ft_error_no(int err)
{
	char *error;

	error = strerror(err);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(-1);
}

void	ft_error_no_free(int err, t_cub *cub)
{
	char *error;

	error = strerror(err);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	free(cub->path[0]);
	free(cub->path[1]);
	free(cub->path[2]);
	free(cub->path[3]);
	free(cub->path[4]);
	exit(-1);
}
