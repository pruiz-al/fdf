/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:24 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/11/30 14:15:29 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_keyfunc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((mlx_t *)param);
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf->isom)
		free_isom(fdf, fdf->map);
	if (fdf->map)
		free_map(fdf);
	free(fdf);
}

void	create_map(t_map **map, t_fdf **fdf)
{
	int	h;
	int	w;

	(*fdf)->map = malloc((*map)->height * sizeof(t_map **));
	(*fdf)->map->points = malloc((*map)->height * sizeof(t_point *));
	if (!(*fdf)->map || !(*fdf)->map->points)
		exit(1);
	h = 0;
	while (h < (*map)->height)
	{
		(*fdf)->map->points[h] = malloc((*map)->width * sizeof(t_map));
		if (!(*fdf)->map->points[h])
			exit(1);
		w = 0;
		while (w < (*map)->width)
		{
			(*fdf)->map->points[h][w] = (*map)->points[h][w];
			w++;
		}
		h++;
	}
	(*fdf)->map->height = (*map)->height;
	(*fdf)->map->width = (*map)->width;
}

int	main(int argc, char *argv[])
{
	t_fdf		*fdf;
	mlx_t		*mlx;
	mlx_image_t	*image;

	fdf = NULL;
	init_fdf(&fdf);
	parse_fdf(argc, argv, &fdf);
	mlx = mlx_init(3000, 2300, "FdF", 1);
	if (!mlx)
		return (perror("Error: mlx initialization.\n"), free_fdf(fdf), 1);
	image = mlx_new_image(mlx, 3000, 2300);
	if (!image)
	{
		mlx_close_window(mlx);
		return (perror("Error: mlx image initialization.\n"), free_fdf(fdf), 1);
	}
	project_isom(&fdf);
	draw_map(fdf, image);
	mlx_resize_image(image, mlx->width, mlx->height);
	mlx_image_to_window(mlx, image, 0, 0);
	image->instances[0].y += ((mlx->height / 2)  - 600);
	image->instances[0].x += ((mlx->width) / 2) - 750;
	mlx_key_hook(mlx, &ft_keyfunc, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	free_fdf(fdf);
	return (0);
}
