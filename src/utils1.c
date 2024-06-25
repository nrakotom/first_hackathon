#include "../includes/so_long.h"

void	error_load_prs(t_data *data)
{
	if (data->prs_up[0] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_up[1] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_up[2] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_down[0] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_down[1] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_down[2] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_left[0] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_left[1] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_left[2] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_right[0] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_right[1] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
	if (data->prs_right[2] == NULL)
		ft_exit(data, "Error:\nLoad xpm image #player#\n");
}

void	draw_rect(t_data *data, int x, int y, int w, int h)
{
	int	i;
	int	j;

	i = x;
	j = y;
	while (j < y + h)
	{
		i = x;
		while (i < x + w)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, 0xffffffff);
			i++;
		}
		j++;
	}
}
