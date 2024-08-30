/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:03 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/24 21:42:00 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned long		i;

	str = (unsigned const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0' && (i < n))
	{
		return ((void *)&str[i]);
	}
	return (NULL);
}
/*
int main() {
	const char s[50] = "hello";
	int c = '\0';
	size_t n = 3*sizeof(s[0]);
	printf("%s\n", (char *)memchr(s, c, n));
	printf("%s\n", (char *)ft_memchr(s, c, n));
	return (0);
}*/