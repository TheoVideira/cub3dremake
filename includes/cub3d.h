/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:46:43 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/22 01:43:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MOVE_SPEED 0.06
# define ROTATE_SPEED 0.08
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17
# ifdef __APPLE__
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define RIGHT_KEY 124
#  define LEFT_KEY 123
#  define ESC_KEY 53
# endif
# ifdef __linux__
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define RIGHT_KEY 65363
#  define LEFT_KEY 65361
#  define ESC_KEY 65307
# endif
# include <math.h>
# include <mlx.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_cub
{
	void		*mlx_ptr;
	void		*window;
	int			*screen;
	int			*img;
	int			bmp;
	char		*cub_file_path;
	int			width;
	int			height;
	int			f_color[3];
	int			c_color[3];
	char		**map;
	int			n_sp;
	int			*sp_x;
	int			*sp_y;
	int			*sp_dist;
	char		*path[5];
	void		*ptr[5];
	int			*data[5];
	int			tex_w[5];
	int			tex_h[5];
	double		angle;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			key_forward;
	int			key_backward;
	int			key_left;
	int			key_right;
	int			key_rotate_left;
	int			key_rotate_right;
	int			r;
	int			no;
	int			so;
	int			ea;
	int			we;
	int			s;
	int			f;
	int			c;
	int			no_map;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	int			step_x;
	int			step_y;
	int			side;
	int			tex_id;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	double		step;
	double		tex_pos;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_y;
	int			draw_end_x;
}				t_cub;

typedef struct	s_fileheader
{
	unsigned short int	id;
	unsigned int		size;
	unsigned int		reserved;
	unsigned int		offset;
}				t_fileheader;

typedef struct	s_dibheader
{
	unsigned int		headersize;
	unsigned int		width;
	unsigned int		height;
	unsigned short int	pane;
	unsigned short int	bitcount;
	unsigned char		offset[24];
}				t_dibheader;

typedef struct	s_frame_saver
{
	unsigned char	*buffer;
	size_t			index;
	size_t			size;
}				t_frame_saver;

void			init_cub(t_cub *cub);
int				init_textures(t_cub *cub, int i);
int				quit_window(t_cub *cub);
void			init_input(t_cub *cub);
int				key_press(int key, t_cub *cub);
int				key_release(int key, t_cub *cub);
void			movement_forward_backward(t_cub *cub);
void			movement_left_right_rotate(t_cub *cub);
void			render_wall(t_cub *cub, double *z_buffer);
void			get_resolution(t_cub *cub);
void			get_ceil(t_cub *cub);
void			get_floor(t_cub *cub);
void			get_tex_no(t_cub *cub);
void			init_game_info(t_cub *cub);
void			parse_north(char *line, t_cub *cub);
void			parse_south(char *line, t_cub *cub);
void			parse_east(char *line, t_cub *cub);
void			parse_west(char *line, t_cub *cub);
void			parse_sprite(char *line, t_cub *cub);
void			parse_res(char *line, t_cub *cub);
void			parse_f_color(char *line, t_cub *cub);
void			parse_c_color(char *line, t_cub *cub);
void			check_cub_file(t_cub *cub);
void			check_lines(t_cub *cub);
int				is_identifier(char *str);
void			init_parse_info(t_cub *cub);
void			check_map_1(char *filename, t_cub *cub);
void			check_map(char *filename, t_cub *cub);
void			check_map_2(t_cub *cub);
void			check_resolution(t_cub *cub);
void			check_f_color(t_cub *cub);
void			check_c_color(t_cub *cub);
void			check_no_tex(t_cub *cub);
void			check_so_tex(t_cub *cub);
void			check_ea_tex(t_cub *cub);
void			check_we_tex(t_cub *cub);
void			check_sp_tex(t_cub *cub);
void			check_info(t_cub *cub);
int				check_format(char *filename, char *format);
void			get_map_heigth(char *filename, t_cub *cub);
void			parse_map(char *filename, t_cub *cub);
void			get_map(char *filename, t_cub *cub);
void			create_line_map(char *line, t_cub *cub, int n);
int				is_valid_case(char c);
int				is_pos_case(char c);
void			init_player_values(char c, t_cub *cub, int x, int y);
void			valid_case_player_pos_check(t_cub *cub);
int				check_case(t_cub *cub, int x, int y);
int				parse_cub_file(t_cub *cub, int ac, char **av);
int				can_move(char c);
void			ft_error(char *error, t_cub *cub);
void			ft_error_no(int err, t_cub *cub);
void			ft_error_line(char *error, int n, t_cub *cub);
void			get_sprite(t_cub *cub);
void			parse_args(int ac, char **av, t_cub *cub);
void			render(t_cub *cub);
int				write_fileheader(int fd, t_cub *cub);
int				write_dibheader(int fd, t_cub *cub);
int				write_pixeldata(int fd, t_cub *cub);
int				write_bmp(t_cub *cub, char *filename);
int				save_first_frame(t_cub *cub, char *filename);
void			ft_free_all(t_cub *cub);
void			render_wall_4(t_cub *cub);
void			render_wall_5(t_cub *cub);
void			render_wall_6(t_cub *cub, int x);
void			render_sprite(t_cub *cub, double *zbuffer);
void			render_sprite_1(t_cub *cub, int i);
void			render_sprite_2(t_cub *cub, int s, double *z_buffer);

#endif
