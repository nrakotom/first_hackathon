#include "../includes/mada.h"

int	move_player(int keysym, t_data *data)
{
	int	x;
	int	y;

	x = data->p_x / PIX_W;
	y = data->p_y / PIX_W;
	data->key = keysym;
	if ((keysym == XK_Up || keysym == 'w') && data->map[y - 1][x] != '1')
	{
		move_up(data);
		if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'A' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'B' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'C' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'D' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'E' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'F')
		{
			mlx_destroy_image(data->etn->mlx, data->etn->img[0]);
			mlx_destroy_window(data->etn->mlx, data->etn->win);
			mlx_destroy_display(data->etn->mlx);
			free(data->etn->mlx);
			free(data->etn);
		}

	}
	else if ((keysym == XK_Down || keysym == 's') && data->map[y + 1][x] != '1')
	{
		move_down(data);
		if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'A' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'B' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'C' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'D' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'E' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'F')
		{
			mlx_destroy_image(data->etn->mlx, data->etn->img[0]);
			mlx_destroy_window(data->etn->mlx, data->etn->win);
			mlx_destroy_display(data->etn->mlx);
			free(data->etn->mlx);
			free(data->etn);
		}
	}
	else if ((keysym == XK_Right || keysym == 'd') && data->map[y][x + 1] != '1')
	{
		move_right(data);
		if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'A' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'B' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'C' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'D' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'E' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'F')
		{
			mlx_destroy_image(data->etn->mlx, data->etn->img[0]);
			mlx_destroy_window(data->etn->mlx, data->etn->win);
			mlx_destroy_display(data->etn->mlx);
			free(data->etn->mlx);
			free(data->etn);
		}
	}
	else if ((keysym == XK_Left || keysym == 'a') && data->map[y][x - 1] != '1')
	{
		move_left(data);
		if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'A' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'B' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'C' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'D' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'E' ||
			data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'F')
		{
			mlx_destroy_image(data->etn->mlx, data->etn->img[0]);
			mlx_destroy_window(data->etn->mlx, data->etn->win);
			mlx_destroy_display(data->etn->mlx);
			free(data->etn->mlx);
			free(data->etn);
		}
	}
	return (0);
}

int	key_handler(int keysym, t_data *data)
{
	move_player(keysym, data);
	if (keysym == XK_Escape)
		ft_exit(data, "MISAOTRA !\n");
	return (0);
}

int	close_win(t_data *data)
{
	ft_exit(data, "MISAOTRA !\n");
	return (0);
}

void	window_move(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}
