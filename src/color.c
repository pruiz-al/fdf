/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:56:19 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/11/23 21:43:19 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

uint32_t	ft_getcolor(char *s)
{
	uint32_t	c;

	c = 0;
	while ((*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f'))
	{
		if (*s < 'a')
			c = c * 16 + *s - 48;
		else
			c = c * 16 + *s - 'a' + 10;
		s++;
	}
	return (c);
}

uint32_t	ft_setcolor(char *z)
{
	uint32_t	color;
	char		**tmp;

	color = 0xffffffff;
	if (ft_strchr(z, 'x'))
	{
		tmp = ft_split(z, 'x');
		if (tmp && tmp[1])
			color = ft_getcolor(tmp[1]) * 256 + 0xff;
		free_array(tmp);
	}
	return (color);
}

void	initcolors(t_isom *p1, t_isom *p2)
{
	p1->r = (p1->color >> 24) & 0xFF;
	p1->g = (p1->color >> 16) & 0xFF;
	p1->b = (p1->color >> 8) & 0xFF;
	p2->r = (p2->color >> 24) & 0xFF;
	p2->g = (p2->color >> 16) & 0xFF;
	p2->b = (p2->color >> 8) & 0xFF;
}

uint32_t	ft_drawcolor(t_isom p1, t_isom p2, float current_step, float steps)
{
	uint32_t	color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	float		step;

	step = current_step / steps;
	initcolors(&p1, &p2);
	r = p1.r + (p2.r - p1.r) * step;
	g = p1.g + (p2.g - p1.g) * step;
	b = p1.b + (p2.b - p1.b) * step;
	color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (color);
}
