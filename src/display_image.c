#include "../includes/so_long.h"
#include <stdio.h>

void	display_wall(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./assets/wall4.xpm", &data->h, &data->w);
	if (data->wall == NULL)
		ft_exit(data, "Error:\nLoad xpm image\n");
	mlx_put_image_to_window(data->mlx, data->win, data->wall, data->x, data->y);
	mlx_destroy_image(data->mlx, data->wall);
}

void	display_ground(t_data *data, int y, int x)
{
	draw_rect(data, x, y, 43, 43);
}

void	display_prs(t_data *data, int y, int x)
{
	void	*p_img;

	p_img = NULL;
	if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'A')
	{
		intro(data, "ANTSIRANANA", "./assets/antakarana.xpm");
		sleep(3);
	}
	if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'B')
	{
		intro(data, "MANJUNGA", "./assets/antakarana.xpm");
		sleep(3);
	}
	if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'C')
	{
		intro(data, "TOAMASINA", "./assets/antakarana.xpm");
		sleep(3);
	}
	if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'D')
	{
		intro(data, "ANTANANARIVO", "./assets/antakarana.xpm");
		sleep(3);
	}
	if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'E')
	{
		intro(data, "FIANARANTSOA", "./assets/antakarana.xpm");
		sleep(3);
	}
	if (data->map[data->p_y / PIX_H][data->p_x / PIX_W] == 'F')
	{
		intro(data, "TOLIARA", "./assets/antakarana.xpm");
		sleep(3);
	}
	if (data->direction == 0)
		p_img = data->prs_up[data->anime_prs];
	else if (data->direction == 1)
		p_img = data->prs_down[data->anime_prs];
	else if (data->direction == 2)
		p_img = data->prs_left[data->anime_prs];
	else if (data->direction == 3)
		p_img = data->prs_right[data->anime_prs];
	mlx_put_image_to_window(data->mlx, data->win, p_img, x, y);
	data->anime_prs = (data->anime_prs + 1) % 3;
}

void	display_coin(t_data *data)
{
	data->coin = mlx_xpm_file_to_image(data->mlx, "./assets/province.xpm", &data->h,
			&data->w);
	if (data->coin == NULL)
		ft_exit(data, "Error:\nLoad xpm image\n");
	mlx_put_image_to_window(data->mlx, data->win, data->coin, data->x, data->y);
	mlx_destroy_image(data->mlx, data->coin);
}


void	display_image(t_data *data)
{
	char str[50];
	void *image;
	static int image_index = 0;
	
	if (image_index < 320)
	{
		sprintf(str, "./assets/mada/%d.xpm", image_index);
		image = mlx_xpm_file_to_image(data->mlx, str, &data->h, &data->w);
		mlx_put_image_to_window(data->mlx, data->win, image, data->x, data->y);
	}
	image_index++;
}

