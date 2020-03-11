#include "cub3d.h"

static int  check_end(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line)
		return (0);
	return (1);
}
static int	check_line(char line, int *p)
{
	if (!line)
		return (0);
	if (!ft_isdigit(line))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

static int	check_separator(char *line, int *p)
{
	if (!*line)
		return (0);
	if (*line != ',' || !ft_isdigit(line[1]))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

void		parse_f_color(char *line, t_cub *cub)
{
	int i;

	i = 0;
	cub->f++;
	line++;
	while(ft_isspace(*line))
		line++;
	if (!check_line(*line, &(cub->f_color[0])))
		return ;
	cub->f_color[0] = ft_atoi(line);
	if (cub->f_color[0] < 0 || cub->f_color[0] > 255)
		cub->f_color[0] = -2;
	while (++i < 3)
	{
		while (ft_isdigit(*line))
			line++;
		if (!check_separator(line, &(cub->f_color[i])))
			return ;
		line++;
		cub->f_color[i] = ft_atoi(line);
		if (cub->f_color[i] < 0 || cub->f_color[i] > 255)
			cub->f_color[i] = -2;
	}
	if (!check_end(line))
		cub->f_color[2] = -4;
}

void		parse_c_color(char *line, t_cub *cub)
{
	int i;

	i = 0;
	cub->c++;
	line++;
	while(ft_isspace(*line))
		line++;
	if (!check_line(*line, &(cub->c_color[0])))
		return ;
	cub->c_color[0] = ft_atoi(line);
	if (cub->c_color[0] < 0 || cub->c_color[0] > 255)
		cub->c_color[0] = -2;
	while (++i < 3)
	{
		while (ft_isdigit(*line))
			line++;
		if (!check_separator(line, &(cub->c_color[i])))
			return ;
		line++;
		cub->c_color[i] = ft_atoi(line);
		if (cub->c_color[i] < 0 || cub->c_color[i] > 255)
			cub->c_color[i] = -2;
	}
	if (!check_end(line))
		cub->c_color[2] = -4;
}