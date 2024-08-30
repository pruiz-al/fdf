/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:09:58 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/07 12:56:24 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j]
			&& (haystack[i + j] != '\0') && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*  int main() {
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("%s\n", strnstr(haystack, needle, -1));
	return (0);
}  */