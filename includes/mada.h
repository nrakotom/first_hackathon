
#ifndef MADA_H
# define MADA_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "libft.h"
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>

# define PIX_W 43
# define PIX_H 43

typedef struct s_introd
{
	void	*mlx;
	void	*win;
	void	*img[9];
	int		h;
	int		w;
}			t_introd;

typedef struct s_intro
{
	void	*mlx;
	void	*win;
	void	*img[7];
	int		h;
	int		w;
}			t_intro;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*w_path[4];
	void	*ground;
	void	*coin;
	void	*exit;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	void	*prs_up[3];
	void	*prs_down[3];
	void	*prs_right[3];
	void	*prs_left[3];
	int		direction;
	int		anime_prs;
	int		exit_y;
	int		exit_x;
	int		y;
	int		x;
	int		i;
	int		j;
	int		h;
	int		w;
	int		count;
	int		count_mouv;
	int		line;
	int		key;
	void  	***image_m;
	void	**images_;
	t_intro	*etn;
}			t_data;



char		*read_map(int fd, char *map);
int			init_window(t_data *data);
void		window_move(t_data *data);
void		valid_path(char **map, t_data *data);

// error
void		check_map(t_data *data, char *str);
void		error(char *str);
void		error_map(t_data *data, char *str);
void		error_load_prs(t_data *data);
void		introd(void);

// display image

void		display_wall(t_data *data);
void		display_ground(t_data *data, int y, int x);
void		display_prs(t_data *data, int y, int x);
void		display_coin(t_data *data);
void		display_exit(t_data *data);
void		position_exit(t_data *data);
void		load_player_images(t_data *data);
void		display_image(t_data *data);
void		display_icons(t_data *data, char *s);

// Player
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);

// utils
void		*ft_free(char **s);
void		ft_exit(t_data *data, char *str);
int			count_word(const char *s, char c);
void		intro(t_data *data, char *s, char *s1);
void		draw_rect(t_data *data, int x, int y, int w, int h);
void	coin(t_data *data, int y, int x);
void	draw_coin(t_data *data, int x, int y);

#endif
