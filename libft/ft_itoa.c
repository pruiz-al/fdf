/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:17:06 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/06 20:35:38 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char				*s;
	signed long int		d;
	int					i;

	s = malloc(sizeof(char) * (count(n) + 1));
	d = (signed long int)n;
	i = count(d);
	if (!s)
		return (NULL);
	if (d == 0)
		s[0] = '0';
	else if (d < 0)
	{
		d *= -1;
		s[0] = '-';
	}
	while (d > 0)
	{
		s[--i] = d % 10 + '0';
		d /= 10;
	}
	d = (signed long int)n;
	s[count(d)] = '\0';
	return (s);
}

/* int	main() {
	int n = -42;
	char *s = ft_itoa(n);
	printf("%s\n", s);
	return (0);
}  */
