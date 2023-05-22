/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:27:54 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/22 12:50:34 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	key_w(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	if ((game->map.value[y - 1][x] != '1' && game->map.value[y - 1][x] != 'E')
		|| (game->map.value[y - 1][x] == 'E' && game->map.n_collect == 0))
	{
		if (game->map.value[y - 1][x] == 'C')
			game->map.n_collect--;
		if (game->map.value[y - 1][x] == 'E')
			win(game);
		game->map.value[y - 1][x] = 'P';
		game->map.value[y][x] = '0';
		game->map.y--;
		print_steps(game);
	}
	print_map(game);
}

static void	key_s(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	if ((game->map.value[y + 1][x] != '1' && game->map.value[y + 1][x] != 'E')
		|| (game->map.value[y + 1][x] == 'E' && game->map.n_collect == 0))
	{
		if (game->map.value[y + 1][x] == 'C')
			game->map.n_collect--;
		if (game->map.value[y + 1][x] == 'E')
			win(game);
		game->map.value[y + 1][x] = 'P';
		game->map.value[y][x] = '0';
		game->map.y++;
		print_steps(game);
	}
	print_map(game);
}

static void	key_a(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	if ((game->map.value[y][x - 1] != '1' && game->map.value[y][x - 1] != 'E')
		|| (game->map.value[y][x - 1] == 'E' && game->map.n_collect == 0))
	{
		if (game->map.value[y][x - 1] == 'C')
			game->map.n_collect--;
		if (game->map.value[y][x - 1] == 'E')
			win(game);
		game->map.value[y][x - 1] = 'P';
		game->map.value[y][x] = '0';
		game->map.x--;
		print_steps(game);
	}
	print_map(game);
}

static void	key_d(t_game *game)
{
	int		x;
	int		y;

	x = game->map.x;
	y = game->map.y;
	if ((game->map.value[y][x + 1] != '1' && game->map.value[y][x + 1] != 'E')
		|| (game->map.value[y][x + 1] == 'E' && game->map.n_collect == 0))
	{
		if (game->map.value[y][x + 1] == 'C')
			game->map.n_collect--;
		if (game->map.value[y][x + 1] == 'E')
			win(game);
		game->map.value[y][x + 1] = 'P';
		game->map.value[y][x] = '0';
		game->map.x++;
		print_steps(game);
	}
	print_map(game);
}

int	my_key_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode == UP)
		key_w(game);
	else if (keycode == DOWN)
		key_s(game);
	else if (keycode == RIGHT)
		key_d(game);
	else if (keycode == LEFT)
		key_a(game);
	else if (keycode == ESC)
		exit_game(game, 1, 1);
	return (0);
}
