/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:31:53 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/21 19:30:16 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_img(t_game *game, void *img_ptr, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, img_ptr, i, j);
}

void	*init_img(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin(IMG_PATH, str);
	img = mlx_xpm_file_to_image(game->mlx, path,
			&game->img_width, &game->img_height);
	if (!img)
		error_message("Can't open img files", game, 1, 1);
	free(path);
	return (img);
}

void	show_images(t_game *game)
{
	game->map.space = init_img(game, "space.xpm");
	game->map.player = init_img(game, "player.xpm");
	game->map.wall = init_img(game, "wall.xpm");
	game->map.collect = init_img(game, "collect.xpm");
	game->map.door = init_img(game, "door.xpm");
}

void	print_images(t_game *game, int i, int j)
{
	draw_img(game, game->map.space, j * 50, i * 50);
	if (game->map.value[i][j] == '1')
		draw_img(game, game->map.wall, j * 50, i * 50);
	else if (game->map.value[i][j] == 'P')
		draw_img(game, game->map.player, j * 50, i * 50);
	else if (game->map.value[i][j] == 'C')
		draw_img(game, game->map.collect, j * 50, i * 50);
	else if (game->map.value[i][j] == 'E')
		draw_img(game, game->map.door, j * 50, i * 50);
	else if (game->map.value[i][j] == '0')
		draw_img(game, game->map.space, j * 50, i * 50);
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			print_images(game, i, j);
			j++;
		}
		i++;
	}
}
