/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:17:25 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/02 18:05:23 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long		i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while ((i < n))
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned long)(str1[i] - str2[i]));
		}
		i++;
	}
	return (0);
}
/*
int main() {
	const char s1[50] = "hello";
	const char s2[50] = "holacaracola";
	size_t n = 30;
	printf("%d\n", ft_memcmp(s1,s2,n));
	printf("%d\n", memcmp(s1,s2,n));
	return (0);
}*/