#include "../includes/mada.h"

void	intro(t_data *data, char *s, char *c)
{
	data->etn = malloc(sizeof(t_intro));
	if (data->etn == NULL)
		return ;
	data->etn->mlx = mlx_init();
	data->etn->img[0] = mlx_xpm_file_to_image(data->etn->mlx, c,  &data->etn->h, &data->etn->w);
	data->etn->win = mlx_new_window(data->etn->mlx, 1920, 1080, s);
	mlx_put_image_to_window(data->etn->mlx, data->etn->win, data->etn->img[0], 0, 0);
}
