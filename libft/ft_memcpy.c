/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:39 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/22 20:08:58 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long int	i;
	char				*cdst;
	char				*csrc;

	i = 0;
	cdst = (char *) dst;
	csrc = (char *) src;
	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int main() {
	char *str1 = NULL;
	char *str2 = "segfouylterljshdhghasdh";
    memcpy(str1, str2, 17);
    printf("%s\n",str1);
    return (0);
}*/