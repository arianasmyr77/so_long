/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:49:21 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/21 18:30:45 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_game(t_game *game, int free, int window)
{
	if (free != 0)
		free_all(game->map.value, game->map.height);
	if (window != 0)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
	exit(0);
}

void	error_message(char *str, t_game *game, int free, int window)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit_game(game, free, window);
}

void	win(t_game	*game)
{
	ft_putstr_fd("You won the game ;-))\n", 1);
	exit_game(game, 1, 1);
}

int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	free_all(char **map, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
