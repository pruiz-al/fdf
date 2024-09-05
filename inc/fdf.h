/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paularuizalcarazgmail.com <paularuizalc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:09:23 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/09/05 22:49:19 by paularuizal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

typedef struct s_point {
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_isom {
	int			x;
	int			y;
}				t_isom;


typedef struct s_map {
	int			height;
	int			width;
	t_point		**points;
}				t_map;

typedef struct s_fdf
{
	int			img_height;
	int			img_width;
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
	float		scale;
	t_map		*map;
	t_isom		***isom;
}				t_fdf;

//Libft
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t count, size_t size);
unsigned long	count(char const *s, char c);
char			**freearray(char **str, int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);

//Parse FdF
void			init_fdf(t_fdf **fdf);
int				check_file(char *file);
void			parse_fdf(int argc, char *argv[], t_fdf **fdf);

//Initialize map
void			create_map(t_map **map, t_fdf **fdf);
void			get_map(t_map **map, char **points);
void			get_width(t_map **map, char **points);
int				read_map(int fd, t_fdf **fdf);

//Isometric
void			create_isom(t_map **map, t_fdf **fdf);
void			calculate_maxmin(t_fdf **fdf, int x, int y);
void			calculate_scale(t_fdf **fdf);
void			set_points_scale(t_fdf **fdf);
void			project_isom(t_fdf **fdf);

//Drawing
void    		draw_line(mlx_image_t *image, t_isom p1, t_isom p2);
void    		draw_map(t_fdf *fdf, mlx_image_t *image);

void			ft_keyfunc(mlx_key_data_t keydata, void *param);

#endif