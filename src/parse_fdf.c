/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paularuizalcarazgmail.com <paularuizalc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:27:31 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/09/05 22:11:52 by paularuizal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_file(char *file)
{
	int	i;
	char	**s;

	s = ft_split(file, '.');
	if (!s[0]|| !s[1] || !ft_strnstr(s[1], ".fdf\0", ft_strlen(s[1]) + 1))
		i = 0;
	freearray(s, count(file, '.'));
	i = 1;
	return (i);
}

void	parse_fdf(int argc, char *argv[], t_fdf **fdf)
{
	int		fd;

	if(argc != 2 || !check_file(argv[1]))
	{
		perror("Error: wrong input.\n");
		exit (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: couldn't open the file.\n");
		exit (EXIT_FAILURE);
	}
	if (!read_map(fd, fdf))
	{
		perror("Error: couldn't read the map.\n");
		exit (1);
	}
}