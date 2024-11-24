/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:09:23 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/11/23 21:32:22 by pruiz-al         ###   ########.fr       */
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

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}				t_point;

typedef struct s_isom
{
	float			x;
	float			y;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint32_t		color;
}				t_isom;

typedef struct s_map
{
	int			height;
	int			width;
	t_point		**points;
}				t_map;

typedef struct s_fdf
{
	int			img_height;
	int			img_width;
	float		max_x;
	float		max_y;
	float		min_x;
	float		min_y;
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

//Color
uint32_t		ft_getcolor(char *s);
uint32_t		ft_setcolor(char *z);
void			initcolors(t_isom *p1, t_isom *p2);
uint32_t		ft_drawcolor(t_isom p1, t_isom p2,
					float current_step, float steps);

//Parse FdF
void			init_fdf(t_fdf **fdf);
int				check_file(char *file);
void			parse_fdf(int argc, char *argv[], t_fdf **fdf);

//Initialize map
void			create_map(t_map **map, t_fdf **fdf);
void			get_map(t_fdf **fdf, t_map **map, char **points);
void			get_width(t_fdf **fdf, t_map **map, char **points);
int				read_map(int fd, t_fdf **fdf);

//Isometric
void			create_isom(t_map **map, t_fdf **fdf);
void			calculate_maxmin(t_fdf **fdf, int x, int y);
void			calculate_scale(t_fdf **fdf);
void			set_points_scale(t_fdf **fdf);
void			project_isom(t_fdf **fdf);
void			center_scale(t_fdf **fdf);

//Drawing
void			draw_line(mlx_image_t *image, t_isom p1, t_isom p2);
void			draw_map(t_fdf *fdf, mlx_image_t *image);
void			ft_keyfunc(mlx_key_data_t keydata, void *param);

void			free_fdf(t_fdf *fdf);
void			free_isom(t_fdf *fdf, t_map *map);
void			free_map(t_fdf *fdf);
void			free_matrix(t_map *map);
void			free_array(char **matrix);

#endif