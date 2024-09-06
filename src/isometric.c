/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paularuizalcarazgmail.com <paularuizalc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:25:48 by paularuizal       #+#    #+#             */
/*   Updated: 2024/09/06 22:27:29 by paularuizal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

void	create_isom(t_map **map, t_fdf **fdf)
{
	int	h;
	int	w;

	create_map(map, fdf);
	(*fdf)->isom = malloc((*map)->height * sizeof(t_isom **));
	if (!(*fdf)->isom)
		exit(1);
	h = 0;
	while (h < (*map)->height)
	{
		(*fdf)->isom[h] = malloc((*map)->width * sizeof(t_isom *));
		if (!(*fdf)->isom[h])
			exit(1);
		w = 0;
		while (w < (*map)->width)
		{
			(*fdf)->isom[h][w] = malloc(sizeof(t_isom));
			if (!(*fdf)->isom[h][w])
			exit(1);
			w++;
		}
		h++;
	}
}

void	calculate_maxmin(t_fdf **fdf, int x, int y)
{
	if ((*fdf)->max_x < x)
		(*fdf)->max_x = x;
	if ((*fdf)->min_x > x)
		(*fdf)->min_x = x;
	if ((*fdf)->max_y < y)
		(*fdf)->max_y = y;
	if ((*fdf)->min_y > y)
		(*fdf)->min_y = y;
}

void	calculate_scale(t_fdf **fdf)
{
	int	range_x;
	int	range_y;
	int	scale_x;
	int	scale_y;

	range_x = (*fdf)->max_x - (*fdf)->min_x;
	range_y = (*fdf)->max_y - (*fdf)->min_y;
	scale_x = ((*fdf)->img_width * 0.9) / range_x;
	scale_y = ((*fdf)->img_height * 0.9) / range_y;
	if (scale_x < ((*fdf)->img_height - 10) / range_y)
		(*fdf)->scale = scale_x;
	else
		(*fdf)->scale = scale_y;
}

//Center the points in the window using the scale
void	set_points_scale(t_fdf **fdf)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < (*fdf)->map->height)
	{
		while (w < (*fdf)->map->width)
		{
			(*fdf)->isom[h][w]->x *= (*fdf)->scale;
			(*fdf)->isom[h][w]->y *= (*fdf)->scale;
			(*fdf)->isom[h][w]->x += (*fdf)->img_width / 2;
			(*fdf)->isom[h][w]->y += (*fdf)->img_height / 2;
			w++;
		}
		w = 0;
		h++;
	}
}

//Transform coordinates x and y to project isometric perspective
//of points in 3D to 2D
//Calculate the range of x and y
//Calculate the scale
//Center points using the scale in the window
void	project_isom(t_fdf **fdf)
{
	int		h;
	int		w;
	t_point	p;

	h = 0;
	w = 0;
	while (h < (*fdf)->map->height)
	{
		while (w < (*fdf)->map->width)
		{
			p = (*fdf)->map->points[h][w];
			(*fdf)->isom[h][w]->x = (p.x - p.y) * 0.87; //0.87 es coseno de 30
			(*fdf)->isom[h][w]->y = (p.x + p.y) * 0.5 - p.z; //0.5 es seno de 30
			calculate_maxmin(fdf, (*fdf)->isom[h][w]->x, (*fdf)->isom[h][w]->y);
			w++;
		}
		w = 0;
		h++;
	}
	calculate_scale(fdf);
	set_points_scale(fdf);
}
