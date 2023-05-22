/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:33:25 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/22 13:42:00 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	hook_loop(t_game *game)
{
	print_steps(game);
	return (0);
}

static void	init_game(t_game *game, char *file)
{
	game->map.steps = 0;
	read_map(game, file);
	game->mlx = mlx_init();
	if (!(game->mlx))
		error_message("Failed to load MLX", game, 1, 0);
	game->window = mlx_new_window(game->mlx, game->map.width * 50,
			game->map.height * 50, "Collect all the strawberries!");
	if (!(game->window))
		error_message("Failed to load window", game, 1, 0);
	show_images(game);
	print_map(game);
	print_steps(game);
}

// void	ft_leaks()
// {
// 	system("leaks so_long");
//	atexit(ft_leaks);
// }

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game, argv[1]);
		mlx_hook(game.window, 17, 0, exit_game, &game);
		mlx_key_hook(game.window, my_key_hook, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
