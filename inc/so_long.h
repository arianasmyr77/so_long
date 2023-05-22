/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:42:46 by arforouz          #+#    #+#             */
/*   Updated: 2023/05/22 13:08:33 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define IMG_PATH    "./assets/"

typedef struct s_map
{
	char	**value;
	void	*collect;
	void	*player;
	void	*wall;
	void	*door;
	void	*space;
	int		width;
	int		height;
	int		n_collect;
	int		steps;
	int		foot_prints;
	int		x;
	int		y;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	int			img_height;
	int			img_width;
}						t_game;

void		print_steps(t_game *game);
int			ft_arrlen(char **arr);
void		check_map(t_game *game);
void		check_rectangle(t_game *game);
void		print_map(t_game *game);
void		read_map(t_game	*game, char *file);
void		error_message(char *str, t_game *game, int free, int window);
void		win(t_game	*game);
int			exit_game(t_game *game, int free, int window);
int			my_key_hook(int keycode, t_game *game);
void		draw_img(t_game *game, void *img_ptr, int i, int j);
void		*init_img(t_game *game, char *str);
void		show_images(t_game *game);
void		count_collectables(t_game *game);
void		free_all(char **map, int i);
void		check_is_possible(char *file, t_game *g);
void		check_walls(char **map, t_game *game);
int			msx(char **map);
int			msy(char **map);
char		**copy_map_validation(char *file, t_game *g);
int			ft_strcmp(char *s1, char *s2);

# define WHITE 0xFFFFFF
#endif