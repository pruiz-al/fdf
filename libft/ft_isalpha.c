/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:56:33 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/08 19:43:29 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	n;

	n = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		n = 1;
	}
	return (n);
}

/*#include <stdio.h>
int	main() {
	printf("%d", ft_isalpha(65));
	printf("%d", ft_isalpha(101));
	printf("%d", ft_isalpha(42));
	printf("%d", ft_isalpha(166));
}*/