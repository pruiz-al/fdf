/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:05:16 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/23 17:49:59 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned long		n;
	unsigned long int	i;

	n = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (n);
}
/*
#include <stdio.h>
int main() {
	char str1[50] = "hello";
    char str2[50] = "";
	char strf1[50] = "hello";
	char strf2[50] = "";
    unsigned long n1 = strlcpy(str1, str2, 5);
	unsigned long n2 = ft_strlcpy(strf1, strf2, 5);
    printf("%lu\n", n1);
	printf("%lu\n", n2);
    printf("%s\n", str1);
	printf("%s\n", strf1);
    return (0);
}*/