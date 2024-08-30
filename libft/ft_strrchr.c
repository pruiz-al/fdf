/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:59:50 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/08/30 16:17:05 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	char			*ptr;

	i = ft_strlen(s);
	ptr = (char *)s;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return (&ptr[i]);
		}
		if (i == 0)
			return (NULL);
		i--;
	}
	return (NULL);
}
/*
int main() {
	const char *s = "hello";
	int c = 'h';
	printf("%s\n", ft_strrchr(s,c));
	printf("%s\n", strrchr(s,c));
	return (0);
}*/