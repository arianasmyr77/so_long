/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:51:15 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/21 22:14:27 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	count_collectables(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	game->map.n_collect = 0;
	while (game->map.value[j])
	{
		i = 0;
		while (game->map.value[j][i])
		{
			if (game->map.value[j][i] == 'C')
				game->map.n_collect++;
			i++;
		}
		j++;
	}
}

void	check_extension(char *map, char *ext, t_game *game)
{
	int	i;
	int	j;

	i = ft_strlen(map) - ft_strlen(ext);
	j = 0;
	while (map[i + j] && ext[j])
	{
		if (map[i + j] == ext[j])
			j++;
		else
		{
			error_message("wrong type of map", game, 0, 0);
			exit(1);
		}
	}
}

static void	copy_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	check_extension(file, ".ber", game);
	i = 0;
	fd = open(file, O_RDONLY);
	game->map.value = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.value)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			if (!line)
				break ;
			game->map.value[i] = line;
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	game->map.value[i] = NULL;
}

void	read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_message("Failed to open file", game, 0, 0);
	line = get_next_line(fd);
	if (!line)
		error_message("Empty map", game, 0, 0);
	game->map.height = 1;
	game->map.width = ft_strlen(line) - 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strcmp(line, "\n") != 0)
			game->map.height++;
		free(line);
	}
	close(fd);
	copy_map(game, file);
	check_map(game);
	check_is_possible(file, game);
}
