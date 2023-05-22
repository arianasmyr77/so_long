/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:21:35 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/21 19:45:00 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_unrecognized(char **map, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\n' && map[j][i] != '\0')
		{
			if (map[j][i] != 'E' && map[j][i] != 'C' && map[j][i] != 'P'
				&& map[j][i] != '0' && map[j][i] != '1')
			{
				error_message("You have some unrecognized elements\n",
					game, 1, 0);
			}
			i++;
		}
		j++;
	}
}

static void	check_elements_helper(int d, int c, int p, t_game *game)
{
	if (d != 1 || c != 1 || p != 1)
		error_message("You have invalid number of elements in your map\n",
			game, 1, 0);
}

static void	set_player_position(int x, int y, int *player, t_game *game)
{
	game->map.x = x;
	game->map.y = y;
	(*player)++;
}

static void	check_elements(char **map, t_game *game)
{
	int	i;
	int	j;
	int	door;
	int	collect;
	int	player;

	door = 0;
	collect = 0;
	player = 0;
	j = -1;
	while (map[++j])
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'E')
				door++;
			else if (map[j][i] == 'C')
				collect = 1;
			else if (map[j][i] == 'P')
				set_player_position(i, j, &player, game);
			i++;
		}
	}
	check_elements_helper(door, collect, player, game);
}

void	check_map(t_game *game)
{
	count_collectables(game);
	check_elements(game->map.value, game);
	check_rectangle(game);
	check_unrecognized(game->map.value, game);
	check_walls(game->map.value, game);
}
