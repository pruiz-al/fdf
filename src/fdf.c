/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:24 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/08/30 21:02:41 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_keyfunc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((mlx_t *)param);
}

int	main(int argc, char *argv[])
{
	t_fdf 		*fdf;
	mlx_t		*mlx;
	mlx_image_t	*image;

	fdf = NULL;
	//init_fdf(fdf); //tengo que inicializar fdf con valores nulos y ya luego después de inicializar el mapa lo igualo fdf->map
	parse_fdf(argc, argv, fdf);
	mlx = mlx_init(1800, 1800, "FdF", 1);
	if (!mlx)
		return (perror("Error: mlx initialization.\n"), 1);
	image = mlx_new_image(mlx, 100, 100);
	if (!image)
	{
		mlx_close_window(mlx);
		return (perror("Error: mlx image initialization.\n"), 1);
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_key_hook(mlx, &ft_keyfunc, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	printf("Estupendo\n");
	return (0);
}
