#include "cub3d.h"

void    check_resolution(t_cub *cub)
{
    if (cub->r == 0)
        ft_error("Missing resolution\n", cub);
    if (cub->r != 1)
        ft_error("Resolution appeared mutliple times\n", cub);
    if (cub->width == -1)
        ft_error("Resolution x parameter didn't appeared\n", cub);
    if (cub->width == -2)
        ft_error("Resolution x parameter is invalid\n", cub);
    if (cub->width == -3)
        ft_error("Separator before x resolution parameter is invalid\n"\
        , cub);
    if (cub->height == -1)
        ft_error("Resolution y parameter didn't appeared\n", cub);
    if (cub->height == -2)
        ft_error("Resolution y parameter is invalid\n", cub);
    if (cub->height == -3)
        ft_error("Separator before y resolution parameter is invalid\n"\
        , cub);
    if (cub->height == -4)
        ft_error("Resolution isn't ended just after y parameter\n", cub);
}

void    check_f_color(t_cub *cub)
{
    if (cub->f == 0)
        ft_error("Missing floor color\n", cub);
    if (cub->f != 1)
        ft_error("Floor color appeared mutliple times\n", cub);
    if (cub->f_color[0] == -1)
        ft_error("Floor red color parameter didn't appeared\n", cub);
    if (cub->f_color[0] == -2)
        ft_error("Floor red color parameter is invalid\n", cub);
    if (cub->f_color[0] == -3)
        ft_error("Separator before floor red color is invalid\n", cub);
    if (cub->f_color[1] == -1)
        ft_error("Floor blue color parameter didn't appeared\n", cub);
    if (cub->f_color[1] == -2)
        ft_error("Floor blue color parameter is invalid\n", cub);
    if (cub->f_color[1] == -3)
        ft_error("Separator before floor blue color is invalid\n", cub);
    if (cub->f_color[2] == -1)
        ft_error("Floor green color parameter didn't appeared\n", cub);
    if (cub->f_color[2] == -2)
        ft_error("Floor green color parameter is invalid\n", cub);
    if (cub->f_color[2] == -3)
        ft_error("Separator before floor green color is invalid\n", cub);
    if (cub->f_color[2] == -4)
        ft_error("Floor color isn't ended just after green parameter\n"\
        , cub);
}

void    check_c_color(t_cub *cub)
{
    if (cub->c == 0)
        ft_error("Missing ceil color\n", cub);
    if (cub->c != 1)
        ft_error("Ceil color appeared mutliple times\n", cub);
    if (cub->c_color[0] == -1)
        ft_error("Ceil red color parameter didn't appeared\n", cub);
    if (cub->c_color[0] == -2)
        ft_error("Ceil red color parameter is invalid\n", cub);
    if (cub->c_color[0] == -3)
        ft_error("Separator before ceil red color is invalid\n", cub);
    if (cub->c_color[1] == -1)
        ft_error("Ceil blue color parameter didn't appeared\n", cub);
    if (cub->c_color[1] == -2)
        ft_error("Ceil blue color parameter is invalid\n", cub);
    if (cub->c_color[1] == -3)
        ft_error("Separator before ceil blue color is invalid\n", cub);
    if (cub->c_color[2] == -1)
        ft_error("Ceil green color parameter didn't appeared\n", cub);
    if (cub->c_color[2] == -2)
        ft_error("Ceil green color parameter is invalid\n", cub);
    if (cub->c_color[2] == -3)
        ft_error("Separator before ceil green color is invalid\n", cub);
    if (cub->c_color[2] == -4)
        ft_error("Ceil color isn't ended just after green parameter\n"\
        , cub);
}

int     check_format(char *filename, char *format)
{
    int     i;
    int     j;
    char    *x;

    x = ft_strrchr(filename, '.');
    if (!x || !format)
        return (1);
    i = ft_strlen(x);
    j = ft_strlen(format);
    return (ft_strncmp(format, x, ft_max(i, j)));
}