/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:44:54 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/11/23 21:42:34 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_isom(t_fdf *fdf, t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (fdf->isom[h][w])
				free(fdf->isom[h][w]);
			w++;
		}
		if (fdf->isom[h])
			free(fdf->isom[h]);
		h++;
	}
	if (fdf->isom)
		free(fdf->isom);
}

void	free_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map->height)
	{
		free(fdf->map->points[i]);
		i++;
	}
	free(fdf->map->points);
	free(fdf->map);
}

void	free_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	free(map);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
