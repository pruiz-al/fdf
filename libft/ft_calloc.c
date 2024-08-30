/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:36:01 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/23 15:05:18 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(size * count);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}
/*
int main() {
    int *ptr;
    unsigned long count = 5;
    unsigned long size = sizeof(int);
    unsigned long i = 0;
    
    ptr = (int *) calloc(count, size);
    while(i < count*size)
    {
        ptr[i] = 1;
        i++;
    }
    while (i < count*size)
    {
        printf("%d", ptr[i]);
        i++;
    }
    free(ptr);
    return(0);
}*/