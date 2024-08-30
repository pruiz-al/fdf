/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:12:10 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/23 16:28:30 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char				*ptr;
	unsigned long int	i;
	unsigned long		n;

	n = ft_strlen(s1) + 1;
	ptr = (char *)malloc(n);
	i = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main() {
	const char *s1 = "hello";
	char *ptr = ft_strdup(s1);
	size_t i = 0;
	
	while (i < ft_strlen(ptr))
	{
		printf("%c", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}*/