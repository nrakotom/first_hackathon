#include "../includes/mada.h"

void	ft_exit(t_data *data, char *str)
{
	int	i;

	i = 0;
	ft_putstr(str);
	while (i < 3)
	{
		mlx_destroy_image(data->mlx, data->prs_up[i]);
		mlx_destroy_image(data->mlx, data->prs_down[i]);
		mlx_destroy_image(data->mlx, data->prs_right[i]);
		mlx_destroy_image(data->mlx, data->prs_left[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free(data->map);
	free(data);
	exit(0);
}

void	error(char *str)
{
	ft_putstr(str);
	exit (0);
}

void	error_map(t_data *data, char *str)
{
	ft_putstr(str);
	ft_free(data->map);
	free(data);
	exit (0);
}

char	*read_map(int fd, char *map)
{
	char	str;
	int		i;
	int		readed;

	readed = 1;
	i = 0;
	while (readed != 0)
	{
		readed = read(fd, &str, 1);
		if (readed == -1)
			return (0);
		if (readed != 0)
			map[i++] = str;
		map[i] = '\0';
	}
	if (i == 0)
		return (0);
	close(fd);
	return (map);
}

static void	init_introd(t_introd *ro)
{
	ro->img[0] = mlx_xpm_file_to_image(ro->mlx, "./assets/0.xpm",
			&ro->h, &ro->w);
	ro->img[1] = mlx_xpm_file_to_image(ro->mlx, "./assets/1.xpm",
			&ro->h, &ro->w);
	ro->img[2] = mlx_xpm_file_to_image(ro->mlx, "./assets/2.xpm",
			&ro->h, &ro->w);
	ro->img[3] = mlx_xpm_file_to_image(ro->mlx, "./assets/3.xpm",
			&ro->h, &ro->w);
	ro->img[4] = mlx_xpm_file_to_image(ro->mlx, "./assets/4.xpm",
			&ro->h, &ro->w);
	ro->img[5] = mlx_xpm_file_to_image(ro->mlx, "./assets/5.xpm",
			&ro->h, &ro->w);
	ro->img[6] = mlx_xpm_file_to_image(ro->mlx, "./assets/6.xpm",
			&ro->h, &ro->w);
	ro->img[7] = mlx_xpm_file_to_image(ro->mlx, "./assets/7.xpm",
			&ro->h, &ro->w);
	ro->img[8] = mlx_xpm_file_to_image(ro->mlx, "./assets/8.xpm",
			&ro->h, &ro->w);
}
void	introd(void)
{
	t_introd	*ro;
	int		i;
	i = 0;
	ro = malloc(sizeof(t_introd));
	if (ro == NULL)
		return ;
	ro->mlx = mlx_init();
	init_introd(ro);
	ro->win = mlx_new_window(ro->mlx, 1920, 1080, "TRATRY NY ASARAMANITRA");
	while (i < 9)
	{
		mlx_put_image_to_window(ro->mlx, ro->win, ro->img[i++], 0, 0);
		usleep(400000);
	}
	while (i--)
		mlx_destroy_image(ro->mlx, ro->img[i]);
	mlx_destroy_window(ro->mlx, ro->win);
	mlx_destroy_display(ro->mlx);
	free(ro->mlx);
	free(ro);
}
