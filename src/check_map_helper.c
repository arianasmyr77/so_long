/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 06:16:21 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/22 13:41:45 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_rectangle(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (game->map.value[i])
	{
		size = ft_strlen(game->map.value[i]) - 1;
		if (!ft_strchr(game->map.value[i], '\n'))
			size += 1;
		if (size % game->map.width != 0)
			error_message("Map is not rectangular\n", game, 1, 0);
		i++;
	}
}

void	check_walls(char **map, t_game *game)
{
	size_t	i;
	int		j;
	size_t	row_length;

	j = 0;
	while (map[j])
	{
		i = 0;
		row_length = ft_strlen(map[j]);
		if (map[j][row_length - 1] == '\n')
			row_length--;
		while (i < row_length)
		{
			if ((j == 0 || j == game->map.height - 1) && map[j][i] != '1')
				error_message("Map is not surrounded by walls\n", game, 1, 0);
			if ((i == 0 || i == row_length - 1) && map[j][i] != '1')
				error_message("Map is not surrounded by walls\n", game, 1, 0);
			i++;
		}
		j++;
	}
}
