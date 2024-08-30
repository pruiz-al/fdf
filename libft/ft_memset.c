/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:21:17 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/18 18:18:16 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned long int	i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *) ptr;
	while (i < num)
	{
		str[i] = (unsigned char) value;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int main() {
	char str1[70] = "hello, my name is paula";
	char str2[70] = "hello, my name is paula";
    ft_memset(str1 + 5, ',', 50*sizeof(str1[0]));
	memset(str2 + 5, ',', 50*sizeof(str2[0]));
    printf("%s\n",str1);
	printf("%s\n",str2);
    return (0);
}*/