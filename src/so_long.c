/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 08:48:37 by fharifen          #+#    #+#             */
/*   Updated: 2024/06/25 11:16:16 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>

// int	check_argv(char *av)
// {
// 	const char	*ber;
// 	int			i;
// 	int			j;
//
// 	ber = ".ber";
// 	i = ft_strlen(av);
// 	if (i < 5)
// 		return (0);
// 	j = 4;
// 	while (j)
// 		if (av[--i] != ber[--j])
// 			return (0);
// 	return (1);
// }

static void	init_plus(t_data *data)
{
	data->height *= PIX_H;
	data->width = ft_strlen(data->map[0]);
	data->width *= PIX_W;
	data->count = 0;
	data->count_mouv = 0;
	load_player_images(data);
	error_load_prs(data);
	data->direction = 1;
	data->anime_prs = 0;
}

void	init_data(t_data *data, int fd, char *map)
{
	char	*str;

	str = read_map(fd, map);
	if (str == NULL)
	{
		free(data);
		error("ERROR: EMPTY MAP\n");
	}
	data->map = ft_split(str, '\n');
	if (data->map == NULL)
		return ;
	data->mlx = mlx_init();
	data->height = 0;
	data->width = 0;
	while (data->map[data->height] != NULL)
		data->height++;
	init_plus(data);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	map[9999];
	t_data	*data;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Error\n Read map\n");
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	init_data(data, fd, map);
	init_window(data);
	window_move(data);
	return (0);
}
