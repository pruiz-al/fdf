/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:10:39 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:50 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*str;
	unsigned long		i;
	unsigned long		j;

	str = NULL;
	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	while (s1[i] && (found(set, s1[i]) == 1))
		i++;
	while (s1[j - 1] && (found(set, s1[j - 1]) == 1))
		j--;
	if (j > i)
		str = (char *)malloc(j - i + 1);
	else
		return (ft_strdup(""));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &((char *)s1)[i], j - i + 1);
	return (str);
}
/*
int main() {
	char *s1 = "ajajajjahelloaja";
	char *set = "ja";
	char *str = ft_strtrim(s1, set);
	printf("%s\n", str);
	return (0);
}*/