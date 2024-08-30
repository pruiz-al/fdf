/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:03:43 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/18 18:17:37 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	n;

	n = 0;
	if ((c >= '0' && c <= '9'))
	{
		n = 1;
	}
	return (n);
}
/*
#include <stdio.h>
int	main() {
	printf("%d", ft_isdigit(49));
	printf("%d", ft_isdigit(101));
	printf("%d", ft_isdigit(55));
	printf("%d", ft_isdigit(166));
}*/