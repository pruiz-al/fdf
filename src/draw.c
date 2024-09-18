/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paularuizalcarazgmail.com <paularuizalc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:27:02 by paularuizal       #+#    #+#             */
/*   Updated: 2024/09/18 17:17:25 by paularuizal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h" //revisar a partir de bresenham de render

//Draw lines using Bresenham's algorithm
void    draw_line(t_fdf *fdf, mlx_image_t *image, t_isom p1, t_isom p2)
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
/*     if ((p2.x - p1.x) < (p2.y - p1.y)) //decide according to the slope
        steps = dy;
    else
        steps = dx; */
    steps = fmax(dx, dy);
    increment_x = (p2.x - p1.x) / steps; //increments each axis to know which points to draw
    increment_y = (p2.y - p1.y) / steps;
    x = p1.x;
    y = p1.y;
    if (!fdf)
        exit (1);
    while (i < steps) //to draw the points between the start (p1) and end (p2) point
    {
    	mlx_put_pixel(image, x, y, 0xFFFFFF);
        x += increment_x;
        y += increment_y;
		i++;
    }
}

//Draw the connections between points (lines) of all the map (wireframe)
void    draw_map(t_fdf *fdf, mlx_image_t *image)
{
    int h;
    int w;

    h = 0;
    w = 0;
    while (h < (fdf)->map->height)
    {
        while (w < (fdf)->map->width)
        {
            if (w < (fdf)->map->width - 1) //Draw the line to the right
                draw_line(fdf, image, *(fdf)->isom[h][w], *(fdf)->isom[h][w + 1]);
            if (h < (fdf)->map->height - 1) //Draw the line down
                draw_line(fdf, image, *(fdf)->isom[h][w], *(fdf)->isom[h + 1][w]);
            w++;
        }
        w = 0;
        h++;
    }
}
