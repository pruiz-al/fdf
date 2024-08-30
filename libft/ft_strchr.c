/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:31:37 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/17 19:56:27 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
/*
int main() {
	const char s[50] = "hello";
	int c = 'e';
	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
	return (0);
}*/