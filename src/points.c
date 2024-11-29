/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:08:19 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/08/31 14:30:45 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//Transform coordinates x and y to project isometric perspective
//of points in 3D to 2D
//quiero almacenar los puntos ya en isométrico en fdf y buscar también el rango
//de x y de y para centrar luego el mapa
t_isom	project_isom(t_fdf fdf, t_map *map)
{
	t_isom	new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fdf.map = (map->points[j][i].x - p.y) * cos(M_PI / 6); //M_PI/6 es 30 grados en radianes
	new.y = (p.x + p.y) * sin(M_PI / 6) - p.z;
	return (new);
}