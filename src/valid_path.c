
#include "../includes/mada.h"

static void	position_p(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	mark_way(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	mark_way(map, i + 1, j);
	mark_way(map, i - 1, j);
	mark_way(map, i, j + 1);
	mark_way(map, i, j - 1);
}

static void	check_way(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P')
			{
				ft_free(map);
				error_map(data, "Error\nPlayer have not access\n");
			}
			j++;
		}
		i++;
	}
}

void	valid_path(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	position_p(map, &j, &i);
	mark_way(map, i, j);
	check_way(map, data);
}
