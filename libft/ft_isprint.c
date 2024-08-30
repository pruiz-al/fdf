/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:46:37 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/08 19:43:40 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	n;

	n = 0;
	if ((c >= 32 && c <= 126) || (c >= 040 && c <= 0176))
	{
		n = 1;
	}
	return (n);
}
/*
#include <stdio.h>
int	main() {
	printf("%d", ft_isprint(49));
	printf("%d", ft_isprint(101));
	printf("%d", ft_isprint(55));
	printf("%d", ft_isprint(078));
}*/