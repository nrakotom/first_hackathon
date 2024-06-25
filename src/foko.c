#include "../includes/so_long.h"

void	init_intro(t_intro *ro)
{
	ro->img[0] = mlx_xpm_file_to_image(ro->mlx, "./assets/antakarana.xpm",
			&ro->h, &ro->w);
	ro->img[1] = mlx_xpm_file_to_image(ro->mlx, "./assets/intro/1.xpm",
			&ro->h, &ro->w);
	ro->img[2] = mlx_xpm_file_to_image(ro->mlx, "./assets/intro/2.xpm",
			&ro->h, &ro->w);
	ro->img[3] = mlx_xpm_file_to_image(ro->mlx, "./assets/intro/3.xpm",
			&ro->h, &ro->w);
	ro->img[4] = mlx_xpm_file_to_image(ro->mlx, "./assets/intro/4.xpm",
			&ro->h, &ro->w);
	ro->img[5] = mlx_xpm_file_to_image(ro->mlx, "./assets/intro/5.xpm",
			&ro->h, &ro->w);
	ro->img[6] = mlx_xpm_file_to_image(ro->mlx, "./assets/intro/6.xpm",
			&ro->h, &ro->w);
}

void	intro(t_data *data, char *s, char *c)
{
	data->etn = malloc(sizeof(t_intro));
	if (data->etn == NULL)
		return ;
	data->etn->mlx = mlx_init();
	// init_intro(data->etn);
	data->etn->img[0] = mlx_xpm_file_to_image(data->etn->mlx, c,  &data->etn->h, &data->etn->w);
	data->etn->win = mlx_new_window(data->etn->mlx, 811, 457, s);
	mlx_put_image_to_window(data->etn->mlx, data->etn->win, data->etn->img[0], 0, 0);
}
