/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:15:32 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/23 17:25:35 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long int	i;
	unsigned char		*strdst;
	unsigned char		*strsrc;

	i = 0;
	strdst = (unsigned char *) dst;
	strsrc = (unsigned char *) src;
	if (strdst == NULL && strsrc == NULL)
		return (NULL);
	if (strdst > strsrc)
	{
		while (len > 0)
		{
			len--;
			strdst[len] = strsrc[len];
		}
		return (dst);
	}
	while (i < len)
	{
		strdst[i] = (unsigned char) strsrc[i];
		i++;
	}
	return (dst);
}
//la parte de debajo del segundo if es el else, 
//pero se ha eliminado por superar el máximo de líneas
/*
int main() {
	char dst1[30] = "hello";
	char src1[30] = "muy buenas";
	char dst2[30] = "hello";
	char src2[30] = "muy buenas";
	memmove(dst1, src1, 7*sizeof(src1[0]));
	ft_memmove(dst2, src2, 7*sizeof(src2[0]));
	char	*str = memmove(((void *)0), ((void *)0), 5);
	//ft_memmove(((void *)0), ((void *)0), 5);
    printf("%s\n",dst1);
	printf("%s\n",src1);
	printf("%s\n",dst2);
	printf("%s\n",src2);
	printf("%s\n",str);
    return (0);
}*/