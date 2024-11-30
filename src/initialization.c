/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:15:34 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/11/29 20:52:27 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_fdf(t_fdf **fdf)
{
	*fdf = ft_calloc(sizeof(t_fdf), 1);
	if (!(*fdf))
		exit(1);
	(*fdf)->img_height = 1000;
	(*fdf)->img_width = 1300;
	(*fdf)->max_x = INT_MIN;
	(*fdf)->max_y = INT_MIN;
	(*fdf)->min_x = INT_MAX;
	(*fdf)->min_y = INT_MAX;
	(*fdf)->scale = 1;
	(*fdf)->map = NULL;
	(*fdf)->isom = NULL;
}

void	store_point(t_map **map, int h, int w, char **tmp)
{
	(*map)->points[h][w].x = w;
	(*map)->points[h][w].y = h;
	(*map)->points[h][w].z = ft_atoi(tmp[w]);
	(*map)->points[h][w].color = ft_setcolor(tmp[w]);
}

//Read the map and store the points in the matrix
void	get_map(t_fdf **fdf, t_map **map, char **points)
{
	int		h;
	int		w;
	char	**tmp;

	h = 0;
	w = 0;
	(*map)->points = malloc((*map)->height * sizeof(t_point *));
	if (!(*map)->points)
		exit(1);
	while (h < (*map)->height)
	{
		(*map)->points[h] = malloc((*map)->width * sizeof(t_point));
		if (!(*map)->points[h])
			exit(1);
		tmp = ft_split(points[h], ' ');
		if (!tmp)
		{
			free_array(tmp);
			free_fdf(*fdf);
			exit(1);
		}
		while (w < (*map)->width)
		{
			store_point(map, h, w, tmp);
			w++;
		}
		w = 0;
		free_array(tmp);
		h++;
	}
}

//Calculate the width (number of columns) 
//Call the function for calculate the points
void	get_width(t_fdf **fdf, t_map **map, char **points)
{
	int	h;
	int	w;

	h = 0;
	w = count(points[h], ' ');
	while (h < (*map)->height)
	{
		if ((int)count(points[h], ' ') != w)
		{
			write(1, "Error reading map.\n", 19);
			exit (1);
		}
		h++;
	}
	(*map)->width = w;
	get_map(fdf, map, points);
}

//Calculate the height (number of rows)
//Calculate the width (number of columns) and the points
int	read_map(int fd, t_fdf **fdf)
{
	t_map	*map;
	char	**points;
	char	*line;
	int		h;

	line = get_next_line(fd);
	map = ft_calloc(1024, sizeof(struct t_map *));
	points = ft_calloc(1024, sizeof(char *));
	if (!line || !map || !points)
	{
		free(line);
		free(map);
		free(points);
		return (-1);
	}
	h = 0;
	while (line)
	{
		points[h] = line;
		line = get_next_line(fd);
		h++;
	}
	close(fd);
	map->height = h;
	get_width(fdf, &map, points);
	create_isom(&map, fdf);
	freearray(points, map->height);
	free_matrix(map);
	return (1);
}
