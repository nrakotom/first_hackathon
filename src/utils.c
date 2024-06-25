/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:39:48 by fharifen          #+#    #+#             */
/*   Updated: 2024/06/11 08:45:07 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
