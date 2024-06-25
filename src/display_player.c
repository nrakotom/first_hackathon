#include "../includes/so_long.h"

void	draw_coin(t_data *data, int x, int y)
{
	data->coin = mlx_xpm_file_to_image(data->mlx, "./assets/province.xpm", &data->h, &data->w);
	if (data->coin == NULL)
		ft_exit(data, "Error:\nLoad xpm image\n");
	mlx_put_image_to_window(data->mlx, data->win, data->coin, y, x);
	mlx_destroy_image(data->mlx, data->coin);
}

void	move_up(t_data *data)
{
	data->p_y -= PIX_W;
	data->direction = 0;
	data->count_mouv++;
	if (data->map[(data->p_y + PIX_W) / 43][data->p_x / 43] == 'A' ||
		data->map[(data->p_y + PIX_W) / 43][data->p_x / 43] == 'B' ||
		data->map[(data->p_y + PIX_W) / 43][data->p_x / 43] == 'C' ||
		data->map[(data->p_y + PIX_W) / 43][data->p_x / 43] == 'D' ||
		data->map[(data->p_y + PIX_W) / 43][data->p_x / 43] == 'E' ||
		data->map[(data->p_y + PIX_W) / 43][data->p_x / 43] == 'F')
		draw_coin(data, data->p_y + PIX_W, data->p_x);
	else
		display_ground(data, data->p_y + PIX_W, data->p_x);
	display_prs(data, data->p_y, data->p_x);
}

void	move_down(t_data *data)
{
	data->p_y += PIX_W;
	data->direction = 1;
	data->count_mouv++;
	if (data->map[(data->p_y - PIX_W) / 43][data->p_x / 43] == 'A' ||
		data->map[(data->p_y - PIX_W) / 43][data->p_x / 43] == 'B' ||
		data->map[(data->p_y - PIX_W) / 43][data->p_x / 43] == 'C' ||
		data->map[(data->p_y - PIX_W) / 43][data->p_x / 43] == 'D' ||
		data->map[(data->p_y - PIX_W) / 43][data->p_x / 43] == 'E' ||
		data->map[(data->p_y - PIX_W) / 43][data->p_x / 43] == 'F')
		draw_coin(data, data->p_y - PIX_W, data->p_x);
	else
		display_ground(data, data->p_y - PIX_W, data->p_x);
	display_prs(data, data->p_y, data->p_x);
}

void	move_right(t_data *data)
{
	data->p_x += PIX_W;
	data->direction = 3;
	data->count_mouv++;
	if (data->map[data->p_y / 43][(data->p_x - PIX_W) / 43] == 'A' ||
		data->map[data->p_y / 43][(data->p_x - PIX_W) / 43] == 'B' ||
		data->map[data->p_y / 43][(data->p_x - PIX_W) / 43] == 'C' ||
		data->map[data->p_y / 43][(data->p_x - PIX_W) / 43] == 'D' ||
		data->map[data->p_y / 43][(data->p_x - PIX_W) / 43] == 'E' ||
		data->map[data->p_y / 43][(data->p_x - PIX_W) / 43] == 'F')
		draw_coin(data, data->p_y, data->p_x - PIX_W);
	else
		display_ground(data, data->p_y, data->p_x - PIX_W);
	display_prs(data, data->p_y, data->p_x);
}

void	move_left(t_data *data)
{
	data->p_x -= PIX_W;
	data->direction = 2;
	data->count_mouv++;
	if (data->map[data->p_y / 43][(data->p_x + PIX_W) / 43] == 'A' ||
		data->map[data->p_y / 43][(data->p_x + PIX_W) / 43] == 'B' ||
		data->map[data->p_y / 43][(data->p_x + PIX_W) / 43] == 'C' ||
		data->map[data->p_y / 43][(data->p_x + PIX_W) / 43] == 'D' ||
		data->map[data->p_y / 43][(data->p_x + PIX_W) / 43] == 'E' ||
		data->map[data->p_y / 43][(data->p_x + PIX_W) / 43] == 'F')
		draw_coin(data, data->p_y, data->p_x + PIX_W);
	else
		display_ground(data, data->p_y, data->p_x + PIX_W);
	display_prs(data, data->p_y, data->p_x);
}

