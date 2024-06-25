#include "../includes/so_long.h"

void	load_player_images(t_data *data)
{
	data->prs_up[0] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_up[1] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_up[2] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_down[0] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_down[1] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_down[2] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_left[0] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_left[1] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_left[2] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_right[0] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_right[1] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
	data->prs_right[2] = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->h, &data->w);
}

void	position_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->map[i][j] = '0';
				data->p_x = j * PIX_W;
				data->p_y = i * PIX_H;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	put_image(t_data *data)
{
	display_image(data);
	if (data->map[data->i][data->j] == 'P' || data->map[data->p_y
		/ PIX_H][data->p_x / PIX_W] == '0')
		display_prs(data, data->p_y, data->p_x);
	// if (data->map[data->i][data->j] == '1')
	// 	display_wall(data);
	// if (data->map[data->i][data->j] == '0')
	// 	display_ground(data, data->i * PIX_H, data->j * PIX_W);
	if ((data->map[data->i][data->j] == 'A') || (data->map[data->i][data->j] == 'B')||
		(data->map[data->i][data->j] == 'C')|| (data->map[data->i][data->j] == 'D')||
		(data->map[data->i][data->j] == 'E')|| (data->map[data->i][data->j] == 'F'))
	{
		display_coin(data);
	}
	// if (data->map[data->i][data->j] == 'E')
	// 	display_ground(data, data->i * PIX_H, data->j * PIX_W);
}

int	init_window(t_data *data)
{
	data->i = 0;
	data->y = 0;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "MADAGASCAR");
	position_player(data);
	while (data->map[data->i])
	{
		data->j = 0;
		data->x = 0;
		while (data->map[data->i][data->j])
		{
			put_image(data);
			data->x += PIX_W;
			data->j++;
		}
		data->y += PIX_H;
		data->i++;
	}
	return (0);
}
