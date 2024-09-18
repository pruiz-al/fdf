/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paularuizalcarazgmail.com <paularuizalc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:25:48 by paularuizal       #+#    #+#             */
/*   Updated: 2024/09/18 17:18:00 by paularuizal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"

void	create_isom(t_map **map, t_fdf **fdf)
{
	int	h;
	int	w;

	create_map(map, fdf);
	(*fdf)->isom = malloc((*map)->height * sizeof(t_isom *));
	if (!(*fdf)->isom)
		exit(1);
	h = 0;
	while (h < (*map)->height)
	{
		(*fdf)->isom[h] = malloc((*map)->width * sizeof(t_isom));
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
	if (scale_x < ((*fdf)->img_height - 10.0) / range_y)
		(*fdf)->scale = scale_x;
	else
		(*fdf)->scale = scale_y;
}

//Center the points in the window using the scale
void	set_points_scale(t_fdf **fdf)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	while (h < (*fdf)->map->height)
	{
		while (w < (*fdf)->map->width)
		{
			(*fdf)->isom[h][w]->x = (*fdf)->isom[h][w]->x * (*fdf)->scale;
			(*fdf)->isom[h][w]->y = (*fdf)->isom[h][w]->y * (*fdf)->scale;
			w++;
		}
		w = 0;
		h++;
	}
}

void	center_scale(t_fdf **fdf)
{
	int	x_offset;
	int	y_offset;
	int	h;
	int	w;

	x_offset = (*fdf)->img_width / 2 - ((*fdf)->max_x + (*fdf)->min_x) * (*fdf)->scale / 2.0;
	y_offset = (*fdf)->img_height / 2 - ((*fdf)->max_y + (*fdf)->min_y) * (*fdf)->scale / 2.0 - (*fdf)->img_height * 0.025;
	h = 0;
	while (h < (*fdf)->map->height)
	{
		w = 0;
		while (w < (*fdf)->map->width)
		{
			(*fdf)->isom[h][w]->x += x_offset - 200;
			(*fdf)->isom[h][w]->y += y_offset - 200;
			(*fdf)->isom[h][w]->x *= 2;
			(*fdf)->isom[h][w]->y *= 2;
			printf("Punto: x = %f, y = %f\n", (*fdf)->isom[h][w]->x, (*fdf)->isom[h][w]->y); //hay un punto raro en la y
			w++;
		}
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
			(*fdf)->isom[h][w]->x = (p.x - p.y) * cos(M_PI / 6); //0.87 es coseno de 30
			(*fdf)->isom[h][w]->y = (p.x + p.y) * sin(M_PI / 6) - p.z; //0.5 es seno de 30
			calculate_maxmin(fdf, (*fdf)->isom[h][w]->x, (*fdf)->isom[h][w]->y);
			w++;
		}
		w = 0;
		h++;
	}
	calculate_scale(fdf);
	set_points_scale(fdf);
	center_scale(fdf);
}
