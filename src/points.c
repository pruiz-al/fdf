/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:08:19 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/08/30 20:15:04 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//Transform coordinates x and y to project isometric perspective
//of points in 3D to 2D
t_isom	project_isom(t_point p)
{
	t_isom	new;

	new.x = (p.x - p.y) * cos(M_PI / 6); //M_PI/6 es 30 grados en radianes
	new.y = (p.x + p.y) * sin(M_PI / 6) - p.z;
	return (new);
}