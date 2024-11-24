/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:27:02 by paularuizal       #+#    #+#             */
/*   Updated: 2024/11/23 21:47:24 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//Draw lines using Bresenham's algorithm
void	draw_line(mlx_image_t *image, t_isom p1, t_isom p2)
{
	float	dx;
	float	dy;
	float	steps;
	float	increment_x;
	float	increment_y;
	float	x;
	float	y;
	int		i;

	i = 0;
	dx = fabsf(p2.x - p1.x);
	dy = fabsf(p2.y - p1.y);
	steps = fmax(dx, dy);
	increment_x = dx / steps; //increments each axis to know which points to draw
	increment_y = dy / steps;
	x = p1.x;
	y = p1.y;
	while (i < steps) //to draw the points between the start (p1) and end (p2) point
	{
		mlx_put_pixel(image, x, y, ft_drawcolor(p1, p2, i, steps));
		if (p2.x < p1.x)
			x -= increment_x;
		else
			x += increment_x;
		if (p2.y < p1.y)
			y -= increment_y;
		else
			y += increment_y;
		i++;
	}
}

//Draw the connections between points (lines) of all the map (wireframe)
void	draw_map(t_fdf *fdf, mlx_image_t *image)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < (fdf)->map->height)
	{
		while (w < (fdf)->map->width)
		{
			if (w < (fdf)->map->width - 1) //Draw the line to the right
				draw_line(image, *(fdf)->isom[h][w], *(fdf)->isom[h][w + 1]);
			if (h < (fdf)->map->height - 1) //Draw the line down
				draw_line(image, *(fdf)->isom[h][w], *(fdf)->isom[h + 1][w]);
			w++;
		}
		w = 0;
		h++;
	}
}
