/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:51:19 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/30 14:14:41 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;

	str = NULL;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) > len + start)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
	{
		len = ft_strlen(s) - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

/* int main() {
    char *s = "hello";
    unsigned int start= 2;
    size_t len = 4;
    char *str1 = ft_substr(s, start, len);
    printf("%s\n", str1);
    return (0);
} */