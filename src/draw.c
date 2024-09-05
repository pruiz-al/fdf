/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paularuizalcarazgmail.com <paularuizalc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:27:02 by paularuizal       #+#    #+#             */
/*   Updated: 2024/09/05 22:53:46 by paularuizal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//Draw lines using Bresenham's algorithm
void    draw_line(mlx_image_t *image, t_isom p1, t_isom p2)
{
    int dx;
    int dy;
    int steps;
    int increment_x;
    int increment_y;
    uint32_t x;
    uint32_t y;

    dx = abs(p2.x - p1.x);
    dy = abs(p2.y - p1.y);
    if (dx < dy) //decide according to the slope
        steps = dy;
    else
        steps = dx;
    increment_x = (p2.x - p1.x) / steps; //increments each axis to know which points to draw
    increment_y = (p2.y - p1.y) / steps;
    x = p1.x;
    y = p1.y;
    while (steps--) //to draw the points between the start (p1) and end (p2) point
    {
        if (x >= 0 && x < image->width && y >= 0 && y < image->height)
        {
            mlx_put_pixel(image, x, y, 0xFFFFFF);
        }
        x += increment_x;
        y += increment_y;
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
                draw_line(image, *(fdf)->isom[h][w], *(fdf)->isom[h][w + 1]);
            if (h < (fdf)->map->height - 1) //Draw the line down
                draw_line(image, *(fdf)->isom[h][w], *(fdf)->isom[h + 1][w]);
            w++;
        }
        w = 0;
        h++;
    }
}
