/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:46:43 by tvideira          #+#    #+#             */
/*   Updated: 2020/04/20 03:32:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MOVE_SPEED 0.06
# define ROTATE_SPEED 0.08
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7
# define A_KEY 113
# define B_KEY 11
# define C_KEY 8
# define D_KEY 100
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 113
# define R_KEY 15
# define S_KEY 115
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 122
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6
# define K1_KEY 18
# define K2_KEY 19
# define K3_KEY 20
# define K4_KEY 21
# define K5_KEY 23
# define K6_KEY 22
# define K7_KEY 26
# define K8_KEY 28
# define K9_KEY 25
# define K0_KEY 29
# define SP_KEY 49
# define BQ_KEY 50
# define MN_KEY 27
# define PL_KEY 24
# define SBO_KEY 33
# define SBC_KEY 30
# define BSL_KEY 42
# define SC_KEY 41
# define SQ_KEY 39
# define CM_KEY 43
# define PT_KEY 47
# define SL_KEY 44
# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F11_KEY 110
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define ESC_KEY 65307
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 257
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define EJ_KEY
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71
# define NK1_KEY 83
# define NK2_KEY 84
# define NK3_KEY 85
# define NK4_KEY 86
# define NK5_KEY 87
# define NK6_KEY 88
# define NK7_KEY 89
# define NK8_KEY 91
# define NK9_KEY 92
# define NK0_KEY 82
# define NKEQ_KEY 81
# define NKSL_KEY 75
# define NKWC_KEY 67
# define NKMN_KEY 78
# define NKPL_KEY 69
# define NKPT_KEY 65
# define NKNTR_KEY 76
# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define ALPHA_COMP 3
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
