/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:26:57 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/08/29 20:09:04 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	count(char const *s, char c)
{
	unsigned long	i;
	unsigned long	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**freearray(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i++]);
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	str = NULL;
	i = 0;
	k = 0;
	str = malloc(sizeof(char *) * (count(s, c) + 1));
	if (!str)
		return (NULL);
	while (k < count(s, c))
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		str[k] = ft_substr(s, j, i - j);
		if (!str[k])
			return (freearray(str, k));
		k++;
	}
	str[k] = 0;
	return (str);
}
