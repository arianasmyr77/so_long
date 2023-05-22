/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 05:23:40 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/22 14:26:45 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_c(char **map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	*search_is_p(char **map, int x, int y, char c)
{
	static int	end[2] = {0, 0};
	static int	s_x;
	static int	s_y;

	s_x = msx(map);
	s_y = msy(map);
	if (y < 0 || y >= s_y || x < 0 || x >= s_x
		|| map[y][x] == c)
		return (NULL);
	if (map[y][x] == 'E')
		end[1] += 1;
	else if (map[y][x] == 'C')
		end[0] += 1;
	map[y][x] = c;
	search_is_p(map, x + 1, y, c);
	search_is_p(map, x, y + 1, c);
	search_is_p(map, x, y - 1, c);
	search_is_p(map, x - 1, y, c);
	return (end);
}

int	find_p_x(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == c)
				return (x);
		}
		y++;
	}
	return (0);
}

int	find_p_y(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_is_possible(char *file, t_game *game)
{
	char	**map;
	int		*check;
	int		x;
	int		y;
	int		c;

	map = copy_map_validation(file, game);
	if (!map)
		error_message("Not valid path\n", game, 0, 0);
	c = count_c(map);
	x = find_p_x(map, 'P');
	y = find_p_y(map, 'P');
	check = search_is_p(map, x, y, '1');
	free_all(map, game->map.height);
	if (!(check[0] == c && check[1] == 1))
		error_message("Not valid path\n", game, 0, 0);
}
