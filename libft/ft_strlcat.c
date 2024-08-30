/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:23 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/18 18:19:20 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	n;

	i = ft_strlen(dst);
	j = 0;
	n = ft_strlen(src);
	if (dstsize <= i)
	{
		n += dstsize;
	}
	else
	{
		n += i;
	}
	if (dstsize == 0)
		return (n);
	while (i < (dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (n);
}
/*
int main() {
	unsigned long i = 0;
    char str1[50] = "buenasss";
    char str2[50] = "hello";
	char strf1[50] = "buenasss";
    char strf2[50] = "hello";
    unsigned long n = strlcat(str1, str2, i);
	unsigned long nf = ft_strlcat(strf1, strf2, i);
    printf("Función original: %lu\n", n);
	printf("Mi función: %lu\n", nf);
    printf("Concatenación original: %s\n", str1);
    printf("Mi concatenación: %s\n", strf1);
    return (0);
}*/