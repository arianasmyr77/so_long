/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 05:23:42 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/22 12:51:15 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	msx(char **map)
{
	int	x;

	x = 0;
	while (map[0][x] == '1')
		x++;
	return (x);
}

/* just for the size y of the map */

int	msy(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

static char	**free_all_helper(char **map, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(map[j]);
		j++;
	}
	free(map);
	return (NULL);
}

char	**copy_map_validation(char *file, t_game *c)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (c->map.height + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strcmp(line, "\n") != 0)
			map[i++] = ft_strdup(line);
		if (!map[i - 1])
			return (free_all_helper(map, i - 1));
		free(line);
	}
	free(line);
	map[i] = NULL;
	return (map);
}
